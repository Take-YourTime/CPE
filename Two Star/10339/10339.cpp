#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
	//	clock
	int n, m; 
	const double cycle = 60 * 60 * 12 * 1.0; //	時鐘轉一圈需要的秒數
	
	while(!cin.eof() && cin >> n >> m)
	{
		if(n == 0 && m == 0)
		{
			cout << n << " " << m << " " << "12" << ':' << "00" << '\n';
			continue;
		}
		
		/*
			走過的天數 = cycle / difference
			走過的秒數 = 走過的天數 * (24 * 60 * 60 - n)，因為每天會慢n秒，所以需要-n or -m
			走過的分鐘數 = 走過的秒數 / 60
		*/
		long long int second = (long long int)( ( cycle / abs(n - m) * (2 * cycle * 1.0 - n)) );
		int min = second / 60;
		
		//	因為做整數除法時，小數點後面會無條件捨去
		//	所以需判斷不足一分鐘的秒數是否進位
		//		當剩餘秒數 >= 30秒時，需做進位
		if(second % 60 >= 30)
			min += 1;
		
		
		int hour = (min / 60) % 12;
		
		
		if(hour == 0)
			hour = 12;
		
		min %= 60;
		
		//	output
		printf("%d %d %02d:%02d\n", n, m, hour, min);
	}
	return 0;
}
