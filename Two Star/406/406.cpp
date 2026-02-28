#include <iostream>
#include <cmath>
#include <vector>
#define NUMBER_RANGE 1001	// 1000 + 1
using namespace std;

//	合數表
bool composite[NUMBER_RANGE] = {false};
int prime_count[NUMBER_RANGE] = {0};
vector<int> prime_list;

void setPrimeList(void)
{
	composite[0] = true;
	//	"one" is considered as a prime in this question
	composite[1] = false;
	prime_list.push_back(1);
	prime_count[1] = prime_count[0] + 1;
			
	for(int i = 2; i <= sqrt(NUMBER_RANGE); i++)
	{
		if(composite[i] == false)
		{
			for(int j = (NUMBER_RANGE-1) / i; j >= i; j--)
				if(composite[j] == false)
					composite[i * j] = true;
			
			prime_list.push_back(i);
			prime_count[i] = prime_count[i - 1] + 1;
		}
		else
			prime_count[i] = prime_count[i - 1];
	}
	
	for(int i = sqrt(NUMBER_RANGE) + 1; i < NUMBER_RANGE; i++)
	{
		if(composite[i] == false)
		{
			prime_list.push_back(i);
			prime_count[i] = prime_count[i - 1] + 1;
		}
		else
			prime_count[i] = prime_count[i - 1];
	}

}


int main()
{
	setPrimeList();
	
	int N, C;
	while(!cin.eof() && cin >> N >> C)
	{
		cout << N << ' ' << C << ':';
		
		int length = prime_count[N];
		
		if(length % 2 == 0)
		{
			if(C * 2 >= length)
				for(int i = 0; i < length; i++)
					cout << " " << prime_list[i];
			else
				for(int i = length / 2 - C; i < length / 2 + C; i++)
					cout << " " << prime_list[i];
		}
		else
		{
			if(C * 2 - 1 >= length)
				for(int i = 0; i < length; i++)
					cout << " " << prime_list[i];
			else
				for(int i = length / 2 - (C - 1); i <= length / 2 + (C - 1); i++)
					cout << " " << prime_list[i];
		}
		
		cout << "\n\n";
	}
	return 0;
}
