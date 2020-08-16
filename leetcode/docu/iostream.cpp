#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

ofstream ostrm;
ifstream istrm;
mutex m;

static int 
do_write()
{
	string s ("1234567890\n");
	int count = 1;

	while(1)
	{
		lock_guard<mutex> lg(m);
		ostrm.write(s.c_str(), s.length());
		count++;
		ostrm.flush();
	}
}

static int
do_read()
{
	char a[30];

	while(1)
	{
		lock_guard<mutex> lg(m);
		memset(a, 0, 30);

		istrm.read(a, 10);

//		cout << a << "\n";
	}
}

int main()
{
	string filename("text.txt");

	ostrm.open(filename, ios_base::in | ios_base::out | ios_base::ate | ios_base::binary);
	istrm.open(filename, ios_base::in | ios_base::out | ios_base::binary);

	vector<thread> threads;

	for(int i = 0; i < 10; i++)
	{
		threads.push_back(thread(do_write));
	}

	for(int i = 0; i < 10; i++)
	{
		threads.push_back(thread(do_read));
	}

	for(auto & t : threads)
		t.join();

}

