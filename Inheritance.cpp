#include <iostream>

using namespace std;

class test {
public:
	int x;
private:
	int y;
protected:
	int z;
public:
	test() {}
	void change()
	{
		x = 1; 
		y = 2;
		z = 3;
	}
};

class test1 : public test
{
public:
	test1() {}
	void changenew()
	{
		x = 1;
		//y = 2;
		z = 3;
	}
};

int main()
{
	test1 t;
	t.change();
}