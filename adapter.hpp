#include "stdafx.h"
#include <iostream>

using namespace std;


class Target  {
public:
	virtual ~Target();
	virtual void request() = 0;
};

class Client {
public:
	void request(Target* target) {
		target->request();
	}
};

class Adaptee
{
public:
	void SpecificRequest() { 
		cout << "Adaptee's request"; 
	}
};

class Adapter: public Target {
public: 
	Adapter(Adaptee* p) : adaptee(p) {
	}
	~Adapter() { delete adaptee; }
	void request() {
		adaptee->SpecificRequest();
	}
private:
	Adaptee *adaptee;
};

