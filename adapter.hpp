#include "stdafx.h"
#include <iostream>

class Target
{
public:
	virtual ~Target() {}
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
		std::cout << "Adaptee's request";
	}
};


class Adapter : public Target
{
public:
	Adapter(Adaptee* p) : p_(p) {
	}
	~Adapter() {
		delete p_;
	}
	void request() {
		p_->SpecificRequest();
	}
private:
	Adaptee* p_;
};
