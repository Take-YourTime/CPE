#include <iostream>
#include <string>
using namespace std;

//	20單位為一個小循環
int digit[20] = {0, 1, 5, 2, 8, 3, 9, 2, 8, 7, 7, 8, 4, 7, 3, 8, 4, 1, 5, 4};

//	100單位為一個大循環
int cycle[100] = {0};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	//	整理100單位循環，每經過20循環，尾數都比上次多4，直到重覆
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			cycle[i * 20 + j] = (digit[j] + 4 * i) % 10;
		}
	}
	
	string str;
	while(cin >> str)
	{
		if(str.size() == 1 && str[0] == '0')
			break;
			
		//	紀錄最後兩位數
			//	last one
		int number = str[str.size() - 1] - '0';
			//  last two
		if(str.size() > 1)
			number += (str[str.size() - 2] - '0') * 10;
		
		cout << cycle[number] << '\n';
	}
	
	return 0;
}
