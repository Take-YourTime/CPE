#include <iostream>
#include <vector>
#define NUMBER_RANGE 5000001 //	5000000 + 1
using namespace std;

//	合數表
bool composite[NUMBER_RANGE] = {false};

//	deprime list
bool deprime[NUMBER_RANGE] = {false};

//	如果本身已經是植樹了，就不需要再計算其質因數合
int factor_sum[NUMBER_RANGE] = {0};

void setPrimeList(void)
{
	composite[0] = composite[1] = true;
	
	for(int i = 2; i < NUMBER_RANGE; i++)
	{
		if(composite[i] == false)
		{
			deprime[i] = true;
			
			for(int j = 2; j <= (NUMBER_RANGE-1) / i; j++)
			{
				composite[i * j] = true;
				factor_sum[i * j] += i;
			}
		}
	}	
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	setPrimeList();
	
	int lower, upper;
	
	//	how many deprimes between lower and upper
	int count;
	
	while(cin >> lower && lower != 0)
	{
		cin >> upper;
		
		count = 0;
		
		for(int i = lower; i <= upper; i++)
		{
			if(deprime[i])
				count++;
			else if( !composite[ factor_sum[i] ] )
			{
				deprime[i] = true;
				count++;
			}
		}
		
		cout << count << '\n';
	}
	return 0;
}
