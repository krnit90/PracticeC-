#include <iostream>

using namespace std;

class UnaryMinusFriend {
public:
	int a = 10;
	int b = 20;

	UnaryMinusFriend() {}
	friend void operator-( UnaryMinusFriend&);
};

void operator-( UnaryMinusFriend& Obj)
{
	Obj.a = -Obj.a;
	Obj.b = -Obj.b;
}

int main()
{

	UnaryMinusFriend um1, um2;
	-um2;
}