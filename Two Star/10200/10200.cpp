#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const int NUMBER_RANGE = 10000 * 10000 + 10000 + 41 + 1;
const int EULER_PRIME_RANGE = 10001;

//	the number of Euler prime until this number
int EulerPrime_count[EULER_PRIME_RANGE] = {0};

//	合數表
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

void setEulerNumber(void)
{
	int Euler_prime_count = 0;
	
	for(int i = 0; i < EULER_PRIME_RANGE; i++)
	{
		int index = i * i + i + 41;
		
		if( !composite[index] )
		{
			Euler_prime_count++;
			EulerPrime_count[i] = Euler_prime_count;
		}
		else
		{
			EulerPrime_count[i] = Euler_prime_count;
		}
	}
}

int main()
{
	//	program speed up
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	setPrimeList();
	
	setEulerNumber();
	
	int a, b;
	while(!cin.eof() && cin >> a >> b)
	{
		double Euler_prime_count = EulerPrime_count[b] - EulerPrime_count[a] + (composite[a * a + a + 41] ? 0.0 : 1.0);
		double Euler_Number_count = b - a + 1;
		
		double ans = Euler_prime_count / Euler_Number_count * 100;
		
		// 精確度調準，沒調準的話有些case會差0.01
		ans = ans + 0.0000001;
		cout << fixed << setprecision(2) << ans << '\n';
	}
	return 0;
}
