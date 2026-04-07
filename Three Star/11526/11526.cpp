#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	long long int n;
	int testCase;
	cin >> testCase;
	while(testCase--)
	{
		cin >> n;
		if(n <= 0){
			cout << 0 << '\n';
			continue;
		}
		
		long long int res = 0;
		long long int j;
		long long int nSqrt = (long long int)sqrt(n);
		
		for(long long int i = 1; i <= nSqrt; i++){
			res = res + (n/i);
		}
		
		for(long long int i = nSqrt+1; i <= n; i = j + 1){
			j = n / (n/i);
			res = res + (j-i+1) * (n/i);
		}
		cout << res << '\n';
	}
	return 0;
}
