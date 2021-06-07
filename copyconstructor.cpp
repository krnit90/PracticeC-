#include <iostream>

using namespace std;

class test {
private:
	int len;
	char* p;

public:
	test() :len(0), p(nullptr)
	{
	}

	~test() {
		if (p != nullptr)
			delete p;
	}

	test(const char* _str)
	{
		len = strlen(_str);
		p = new char[len + 1];
		strncpy_s(p, len + 1, _str, len);
	}

	test(const test& _obj) :len(_obj.len), p(new char[len + 1]) 
	{
		strncpy_s(p, len + 1, _obj.p, len);
	}

	test operator=(const test& _obj)
	{
		if (this != &_obj)
		{
			len = _obj.len;
			p = new char[len + 1];
			strncpy_s(p, len + 1, _obj.p, len);
		}
		return *this;
	}

	test(test&& _obj)
	{
		cout << "Move copy assgnment operator called" << endl;
		p = _obj.p;
		len = _obj.len;

		_obj.p = nullptr;
		_obj.len = 0;
		
	}

	test operator=(test&& _obj)
	{
		cout << "Move assgnment operator called" << endl;
		if (this != &_obj)
		{
			p = _obj.p;
			len = _obj.len;

			_obj.p = nullptr;
			_obj.len = 0;
		}
		return *this;
	}

	void display()
	{
		cout << "data: " << p << endl;
		cout << "length: " << len << endl;
	}
	test genenerate()
	{
		test t ;
		t.len = 5;
		t.p = new char[len+1];
		strncpy_s(t.p, len + 1, "hello", len);
		return t;
	}
};



int main()
{
	test t1("nitesh");
	test t2("Singh");
	test t3 =t1;
	
	t1 = t2;

	t3.display();
	t2.display();

	test t4 = t1.genenerate();
	t4.display();

	t3 = t4.genenerate();
	t3.display();




}