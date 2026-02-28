#include <iostream>
#include <cmath>
#define PRIME_LENGTH 1299710 // 1299709 + 1
using namespace std;

int main()
{
	//	build prime list
	bool prime[PRIME_LENGTH];
	
	prime[0] = false;
	prime[1] = false;
	for(int i = 2; i < PRIME_LENGTH; i++)
		prime[i] = true;
	
	for(int i = 2; i < sqrt(PRIME_LENGTH); i++)
		if(prime[i] == true)
			for(int j = (PRIME_LENGTH-1) / i; j >= i; j--)
				if(prime[j] == true)
					prime[i * j] = false;
	
	/*---------------------*/
	
	int n;
	cin >> n;
	while(n != 0)
	{
		if(prime[n] == true)
			cout << 0 << '\n';
		else
		{
			int lowerPrime = n;
			int upperPrime = n;
			do{
				lowerPrime--;
			}while(!prime[lowerPrime]);
			
			do{
				upperPrime++;
			}while(!prime[upperPrime]);
			
			cout << upperPrime - lowerPrime << '\n';
		}
		cin >> n;
	}
		
	return 0;
}
