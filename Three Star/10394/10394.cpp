#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int NUMBER_RANGE = 20000000 + 1;

bool composite[NUMBER_RANGE] = {false};

void setPrimeList(void)
{
	composite[0] = true;
	composite[1] = false;
	
	for(int i = 2; i <= sqrt(NUMBER_RANGE); i++)
	{
		if(composite[i] == false)
		{
			for(int j = (NUMBER_RANGE-1) / i; j >= i; j--)
				if(composite[j] == false)
					composite[i * j] = true;
		}
	}
}

class Number{
	public:
		Number() = default;
		Number(int p1, int p2)
		{
			prime1 = p1;
			prime2 = p2;
		}
		int prime1;
		int prime2;
};


int main()
{
	setPrimeList();
	
	vector<Number> list;
	
	for(int i = 2; i < NUMBER_RANGE - 2; i++)
	{
		if(composite[i] == false && composite[i + 2] == false)
			list.push_back( Number(i, i + 2) );
	}
	
	int index;
	
	while(!cin.eof() && cin >> index)
	{
		index--;
		cout << '(' << list[index].prime1 << ", " << list[index].prime2 << ")\n";
	}
	
	return 0;
}
