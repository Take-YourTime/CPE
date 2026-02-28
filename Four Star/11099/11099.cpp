#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
#define NUMBER_RANGE 1000001 //	1000000 + 1
using namespace std;

//	合數表
bool composite[NUMBER_RANGE] = {false};

//	prime list
vector<long long int> prime;

void setPrimeList(void)
{
	composite[0] = composite[1] = true;
	
	for(int i = 2; i < sqrt(NUMBER_RANGE); i++)
	{	
		if(composite[i] == false)
		{	
			prime.push_back((long long int)i);
			for(int j = i; j <= (NUMBER_RANGE-1) / i; j++)
			{
				composite[i * j] = true;
			}
		}
	}
	
	for(int i = sqrt(NUMBER_RANGE) + 1; i < NUMBER_RANGE; i++)
	{
		if(composite[i] == false)
			prime.push_back((long long int)i);
	}
}


long long int find(vector<long long int> factor, int index, long long int quotient, long long int min, long long int n)
{
	if(index >= factor.size())
		return min;
	
	do{
		long long int temp = find(factor, index + 1, quotient, min, n);
		
		if(min > temp)
			min = temp;
		
		quotient *= factor[index];
	}while(quotient <= n);
	
	if(min > quotient)
		min = quotient;
	
	return min;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	setPrimeList();
	
	long long int n;
	
	while(!cin.eof() && cin >> n)
	{
		if( !composite[n] )
		{
			//	n為質數的情況
			if(n * n < 2000000)
			{
				cout << n * n << '\n';
			}
			else
			{
				cout << "Not Exist!\n";
			}
			continue;
		}
		else if(n == 1)
		{
			cout << "Not Exist!\n";
			continue;
		}
		
		//	質因數
		vector<long long int> factor;
		
		//	商，用來儲存與n擁有相同質因數的最小數
		long long int quotient = 1;
		
		//	儲存n的值
		long long int n_value = n;
		
		//	搜尋質因數
		for(int i = 0; i < prime.size(); i++)
		{
			if(prime[i] > n)
				break;
			else if(n % prime[i] == 0)
			{
				quotient *= prime[i];
				factor.push_back(prime[i]);
				
				do{
					n /= prime[i];
				}while(n % prime[i] == 0);
			}
		}
		
		long long int min = find(factor, 0, quotient, LLONG_MAX, n_value);
		
		if(min < 2000000)
		{
			cout << min << '\n';
		}
		else
		{
			cout << "Not Exist!\n";
		}
	}
	return 0;
}
