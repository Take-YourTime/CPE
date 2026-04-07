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
		
		long long int nSqrt = (long long int)sqrt(n);
		long long int res = 0; // ans
		long long int j; // right bound of current value
		
		for(long long int i = 1; i <= nSqrt; i++){
			res = res + (n/i);
		}
		
		for(long long int i = nSqrt+1; i <= n; i = j + 1){
			j = n / (n/i); // get the rightest bound, let k = i~j, their values are identical
			res = res + (j-i+1) * (n/i);
		}
		cout << res << '\n';
	}
	return 0;
}
