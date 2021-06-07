#include <iostream>

using namespace std;

class MinuzOverload
{
private:
	int a = 10;
public:
	MinuzOverload() {}
	void operator -()
	{
		a = -a;
	}
};
int main()
{
	MinuzOverload m1;
	-m1;
}