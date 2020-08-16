#include "Worker.h"
#include <iostream>

using namespace std;


int main()
{
	Worker *worker = Worker::getWorker();

	worker->id = rand();

	cout << worker->id << "\n";

	/*
	Worker w = *worker;
	Worker w2(*worker);

	Worker w3 (*worker);
	*/

}

