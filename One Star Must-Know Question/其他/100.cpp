#include <iostream>
using namespace std;

int dp[30000000] = {0}; // the max number is bigger than 530000000 !!!


void get_cycle_length(int number, int& cnt)
{
	if(number != 1)
	{
		//	use record data
		if(number < 30000000 && dp[number] != 0){
			cnt += dp[number];
			return;
		}
		
		int temp_cnt = cnt;
		
		// normal step
		cnt++;
		if(number % 2 == 1){
			get_cycle_length(number * 3 + 1, cnt);
		}
		else{
			get_cycle_length(number / 2, cnt);
		}
		
		if(number < 30000000)	dp[number] = cnt - temp_cnt;
	}
	
	return;
}


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
		
	dp[1] = 1;
	
	int left, right;
	int start, end;
	
	while(cin >> left >> right)
	{
		if(cin.eof())	break;
		
		int max = -1;
		int cycle_length;
		
		//	set up the interval
		if(left > right){
			start = right; end = left;
		}
		else{
			start = left; end = right;
		}
		
		
		for(int n = start; n <= end; n++)
		{
			cycle_length = 1;
			
			// go to devide-and-conquer with dp
			get_cycle_length(n, cycle_length);
			
			if(cycle_length > max) max = cycle_length;
		}
		
		cout << left << " " << right << " " << max << '\n';
	}
	
	return 0;
}
