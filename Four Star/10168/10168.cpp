#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//	質數表大小
const int NUMBER_RANGE = 10000000;

//	合數表
bool composite[NUMBER_RANGE] = { false };

void setPrimeList(void)
{
	composite[0] = true;
	composite[1] = true;

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

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	setPrimeList();
	int n;
	
	while(!cin.eof() && cin >> n)
	{
		if(n < 8)
		{
			cout << "Impossible.\n";
			continue;
		}
		
		//	以哥德巴赫猜想來解：「任一大於2的偶數，都可表示成兩個質數之和」
		//	因為此題只要找尋其中一個答案即可
		//	所以我們就找最簡單的那個就好
		
		if(n % 2 == 0)	// 偶數
		{
			cout << "2 2 ";
			n -= 4;
		}
		else	// 奇數
		{
			cout << "2 3 ";
			n -= 5;
		}
		
		
		//	處理剩下的兩個質數
		
		for(int i = 2; i <= n / 2; i++)
		{
			//	以迴圈找質數
			if(!composite[i] && !composite[n - i])
			{
				cout << i << " " << n - i << '\n';
				break;
			}
		}
	}
	return 0;
}
