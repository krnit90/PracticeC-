#include <iostream>

using namespace std;

class Binaryadd
{

	private:
		size_t len = 0;
		char* p = nullptr;

	public:
		Binaryadd(){}
		Binaryadd(const char* str) {
			len = strlen(str);
			p = new char[len + 1];
			strncpy_s(p, len + 1, str, len);
		}
		Binaryadd(const Binaryadd& _obj) : len(_obj.len), p(new char[len + 1])
		{
			strncpy_s(p, len + 1, _obj.p, len);
		}

		Binaryadd operator+(Binaryadd& _obj)
		{
			Binaryadd ba;
			ba.len = (strlen(p) + strlen(_obj.p));
			ba.p = new char[ba.len + 1];

			memset(ba.p, '\0', ba.len + 1);
			strncpy_s(ba.p, len+1,p, len);
			strncat_s(ba.p, ba.len+1,_obj.p,_obj.len);
			return ba;
		}

		~Binaryadd()
		{
			if (p != nullptr)
			{
				delete p;
			}
			//delete p;
		}

		void display()
		{
			cout << "string: " << p << endl;
			cout << "length:  " << len << endl;
		}
	
};

int main()
{
	Binaryadd b1{"nitesh"};
	Binaryadd b2{ "Singh" };
	Binaryadd b3 = b1 + b2;
	b3.display();
	return 0;

}