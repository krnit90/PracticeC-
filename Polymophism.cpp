/*Polymophism: 'It is one of the oops concept, wherein  we can access differrent implementations of member functions with same name.
	Types of polymorphism
		1.Compile time:
		2:Run time 
*/


#include<iostream>

using namespace std;

class A
{
private :
	int a=100;
public :
	virtual void display() {
		cout << "value of A:a -> " << a << endl;
	}
};

class B :public A
{
private:
	int b=110;
public:
	void display() {
		cout << "value of B:b -> " << b << endl;
	}
};

int main()
{
	A* a1 = new B;
	a1->display();

	A* a2 = new A;
	a2->display();

	B* b1 = new B;
	b1->display();

	B* b3 = dynamic_cast<B*>(a2);
	b3->display();

}