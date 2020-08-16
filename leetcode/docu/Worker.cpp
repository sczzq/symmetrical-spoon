#include "Worker.h"

static Worker *worker = NULL;

Worker *Worker::getWorker()
{
	if(worker == NULL)
	{
		worker = new Worker();
	}
	return worker;
}

