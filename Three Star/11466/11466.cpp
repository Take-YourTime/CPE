#include <iostream>
#include <cmath>
using namespace std;

const long long int NUMBER_RANGE = 34000000 + 1;

bool composite[NUMBER_RANGE] = { false };

void setPrimeList(void)
{
	composite[0] = true;
	composite[1] = true;

	for(long long int i = 2; i <= sqrtl(NUMBER_RANGE); i++)
	{
		if(composite[i] == false)
		{
			for(long long int j = (NUMBER_RANGE-1) / i; j >= i; j--)
				if(composite[j] == false)
					composite[i * j] = true;
		}
	}
}

int main()
{
	setPrimeList();
	
	
	long long int n;
	while(cin >> n && n != 0)
	{
		if(n < 0)
		{
			n = -n;
		}
		
		long long int m = 2;
		long long int count = 0; //	how many prime can divide n
		long long int output = 0;
		
		long long int upper_side = min(n + 1, NUMBER_RANGE);
		while(n >= m && m < upper_side)
		{
			if(n % m == 0)
			{
				count++;
				output = m;
				do{	
					n /= m;
				}while(n % m == 0);
			}
			
			do{
				m++;
			}while(composite[m]);
		}
		
		//	n不等於1，代表n為大於34000000的質數
		if(n != 1)
		{
			output = n;
			count++;
		}
		
		
		//	output
		if(count < 2)
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << output << '\n';
		}
			
	}
	return 0;
}
