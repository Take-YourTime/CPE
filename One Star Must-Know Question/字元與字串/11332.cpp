#include <iostream>
using namespace std;

long long int n;

long long int digit_sum(long long int number){
	long long int sum = 0;
	
	while(number > 0){
		sum += number % 10;
		number /= 10;
	}
	
	return sum;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	while(cin >> n)
	{
		if(n == 0)
			break;
		
		while(n >= 10)
		{
			n = digit_sum(n);
		}
		
		cout << n << '\n';
	}
	return 0;
}
