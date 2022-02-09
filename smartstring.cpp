#include<memory>
#include<iostream>
#include <cstring>
class smartstring
{
	public:
		//default constructor
		smartstring() :pbuf(nullptr), length(0) { }

		//copy constructor
		smartstring(smartstring& p) : length(p.len()) {
			pbuf.reset(new char[length + 1]);
			strncpy_s(pbuf.get(), length + 1, p.pbuf.get(), length);
		}

		//parameterized constructor
		//question: why we need explicit  here?
		explicit smartstring(const char* p) {
			length = strlen(p);
			pbuf.reset(new char[length + 1]);
			strncpy_s(pbuf.get(), length + 1, p, length);
		}
		
		//overloaded assignment operator , called when two objects are assigned
		smartstring& operator = (const smartstring& obj) {
			if (this != &obj) {
				length = 0;
				pbuf.release();
				length = obj.len();
				pbuf.reset(new char[length + 1]);
				strncpy_s(pbuf.get(), length + 1, obj.pbuf.get(), length);
			}
			return *this;
		}

		//overloaded assignment operator , called when smartstring object is assigned a char*
		void operator = (const char* p)
		{
			length = strlen(p);
			pbuf.reset(new char[length + 1]);
			strncpy_s(pbuf.get(), length + 1, p, length);
		}

		//returns the length of the buffer
		int len() const { return length; }

		//print method
		void display() { 
			std::cout << pbuf.get() << "\t" << length << std::endl; 
		}

	private:
		std::unique_ptr<char> pbuf;
		int length;
};


int main()
{
	smartstring m("naveen");
	m.display();

	smartstring n(m);
	n.display();

	n = m;
	n.display();

	smartstring s;
	s = "GUPTA";

	s.display();



}
