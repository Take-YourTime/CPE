#include <iostream>
using namespace std;

int main()
{
	long long int n = 1000001;
	
	long long int* sum = new long long int[n];
	
	//	Too less sides to be a triangle
	sum[0] = sum[1] = sum[2] = -1;
	sum[3] = 0;
		
	//	以遞迴公式計算可以得到的三角形數量
	for(long long int i = 4; i < n; i++)
	{
		
		sum[i] = sum[i - 1] + ( (i - 1) * (i - 2) / 2 - (i - 1) / 2 ) / 2;
	}
	
	while(cin >> n && n >= 3)
	{
		cout << sum[n] << '\n';
	}
	
	delete [] sum;
	return 0;
}
