#include <string>


class Worker {
private:
	Worker(){};
//	Worker(const Worker & w) = delete;
public:
	Worker(const Worker & w) = delete;
	Worker(Worker && w) = delete;

	~Worker(){};

	static Worker *getWorker();

	std::string name;
	int id;

};




