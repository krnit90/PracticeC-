#include <iostream>

using namespace std;

class A
{
public: //access specifier would be example for abstraction
	A() :a(0) {};
	~A() {}
	A(int b){
		a=b;
	}
	void setA(int c)
	{
		a = c;
	}

	void display(){
		std::cout << "Display " << a << std::endl;
	}
protected:
	int a;
};

class B : public A //inheritance
{
public:
	B() :b(0) {}
	~B() {}
	B(int a)
	{
		b = a;
	}
	void display()  //Overriding the member function is run time polymorphism
	{
		std::cout << "Display " << b << std::endl;
	}

	void display(int c)  //compiletime polymophism
	{
		std::cout << "Display " << c << std::endl;
	}

	void setB(int c)  //Encapsulation
	{
		b = c;
	}
private:
	int b;
};

int main()
{
	A a1{ 10 };
	B b1{ 20 };

	A* p = &b1;
	p->display();
	//b1.display();

	a1.display();
	b1.display();
	cin.get();

}