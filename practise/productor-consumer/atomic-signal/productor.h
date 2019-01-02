#ifndef _PRODUCTOR_H_

namespace AtomicSignal {

// using same AtomicSingnal in Productor and Consumer.
class AtomicSignal;

// using same pointer of Data in Productor and Consumer.
typedef vector<shared_ptr<char>> Data;

class Productor {
public:
	Productor(shared_ptr<AtomicSignal> as, shared_ptr<Data> data)
	: m_atomic_signal(as),
	  m_data(data)
	{ };
	~Productor() { };

	void p(void *d);

	shared_ptr<AtomicSignal> m_atomic_signal;
	shared_ptr<Data> m_data;
};

class Consumer {
public:
	Consumer(shared_ptr<AtomicSignal> as, shared_ptr<Data> data)
		: m_atomic_signal(as),
		  m_data(data)
	{ };
	~Consumer() { };

	void v(void **d);

	shared_ptr<AtomicSignal> m_atomic_signal;
	shared_ptr<Data> m_data;
};

};

#endif

