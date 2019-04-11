#include <inttypes.h>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <thread>
#include <vector>
#include <iostream>
#include <atomic>

#define OS_LINUX
#if defined(OS_LINUX)
#include <dirent.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#endif  // !OS_LINUX

using namespace std;

inline bool IsLittleEndian() {
  uint32_t x = 1;
  return *reinterpret_cast<char*>(&x) != 0;
}

static std::atomic<int>& ShouldSecondaryWait() {
  static std::atomic<int> should_secondary_wait{1};
  return should_secondary_wait;
}

static std::string Key(uint64_t k) {
  std::string ret;
  if (IsLittleEndian()) {
    ret.append(reinterpret_cast<char*>(&k), sizeof(k));
  } else {
    char buf[sizeof(k)];
    buf[0] = k & 0xff;
    buf[1] = (k >> 8) & 0xff;
    buf[2] = (k >> 16) & 0xff;
    buf[3] = (k >> 24) & 0xff;
    buf[4] = (k >> 32) & 0xff;
    buf[5] = (k >> 40) & 0xff;
    buf[6] = (k >> 48) & 0xff;
    buf[7] = (k >> 56) & 0xff;
    ret.append(buf, sizeof(k));
  }
  size_t i = 0, j = ret.size() - 1;
  while (i < j) {
    char tmp = ret[i];
    ret[i] = ret[j];
    ret[j] = tmp;
    ++i;
    --j;
  }
  return ret;
}

static uint64_t Key(std::string key) {
  assert(key.size() == sizeof(uint64_t));
  size_t i = 0, j = key.size() - 1;
  while (i < j) {
    char tmp = key[i];
    key[i] = key[j];
    key[j] = tmp;
    ++i;
    --j;
  }
  uint64_t ret = 0;
  if (IsLittleEndian()) {
    memcpy(&ret, key.c_str(), sizeof(uint64_t));
  } else {
    const char* buf = key.c_str();
    ret |= static_cast<uint64_t>(buf[0]);
    ret |= (static_cast<uint64_t>(buf[1]) << 8);
    ret |= (static_cast<uint64_t>(buf[2]) << 16);
    ret |= (static_cast<uint64_t>(buf[3]) << 24);
    ret |= (static_cast<uint64_t>(buf[4]) << 32);
    ret |= (static_cast<uint64_t>(buf[5]) << 40);
    ret |= (static_cast<uint64_t>(buf[6]) << 48);
    ret |= (static_cast<uint64_t>(buf[7]) << 56);
  }
  return ret;
}

void secondary_instance_sigint_handler(int signal) {
  ShouldSecondaryWait().store(0, std::memory_order_relaxed);
  fprintf(stdout, "\n");
  fflush(stdout);
};

void RunSecondary() {
  ::signal(SIGINT, secondary_instance_sigint_handler);
  long my_pid = static_cast<long>(getpid());

  std::vector<std::thread> test_threads;

  auto helper = [&]()
  {
    std::srand(time(nullptr));
	int count = 0;
	int kMaxKey = 12345667;
    while (1 == ShouldSecondaryWait().load(std::memory_order_relaxed)) {
	  uint64_t curr_key = std::rand() % kMaxKey;
      string key = Key(curr_key);
	  count++;
	  fprintf(stderr, "count: %d, key: %s\n", count, key.c_str());
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    fprintf(stdout, "[process %ld] Point lookup thread finished\n", my_pid);
  };

  test_threads.emplace_back(helper);
  test_threads.emplace_back(helper);
  test_threads.emplace_back(helper);
  test_threads.emplace_back(helper);
  test_threads.emplace_back(helper);

  while (1 == ShouldSecondaryWait().load(std::memory_order_relaxed)) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  for (auto& thr : test_threads) {
    thr.join();
  }
}

int main(int argc, char** argv) {
    RunSecondary();
  return 0;
}
