#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

//	there are n input of candy amount
int n;

//	the amount of candy
int* candy;

//	candy總重最重為32 * 20 = 640
//	最多有32顆candy

//	紀錄的是以當前條件繼續找下去，以最公平的分法可以找到的最小糖果差
int dp[35][645][645];


//	index: how many candy are used
//	diff1: |A - B|
//	diff2: |A - C|
int solve(int index, int diff1, int diff2)
{
	if(index == n)
		return max(diff1, diff2);
	
	if(dp[index][diff1][diff2] != -1)
		return dp[index][diff1][diff2];
	
	//	主角A
	int ans = solve(index + 1, diff1 + candy[index], diff2 + candy[index]);
	
	//	配角B
	int diff1_p = diff1 - candy[index];
	
	//	此時表示B擁有的糖果量 > A
	if(diff1_p < 0)
		ans = min(ans, solve(index + 1, -diff1_p, diff2 - diff1_p));
	else
		ans = min(ans, solve(index + 1, diff1_p, diff2));

	//配角C
	int diff2_p = diff2 - candy[index];
	
	//	此時表示C擁有的糖果量 > A
	//	min和max的用意是讓d1永遠 < d2，這樣可以避免重複計算
	if(diff2_p < 0)
		ans = min(ans, solve(index + 1, min(diff1 - diff2_p, -diff2_p), max(diff1 - diff2_p, -diff2_p)) );
	else
		ans = min(ans , solve(index + 1, min(diff1, diff2_p), max(diff1, diff2_p)) );

	//	將計算結果存於dp中
	return dp[index][diff1][diff2] = ans;
	//return ans;
	
}

int main()
{
	int test_case;
	cin >> test_case;
	
	for(int test = 1; test <= test_case; test++)
	{
		cin >> n;
		
		//	the all candy
		candy = new int[n];
		
		for(int i = 0; i < n; i++)
		{
			cin >> candy[i];
		}
		
		memset(dp, -1, sizeof(dp));
		
		cout << "Case " << test << ": " << solve(0, 0, 0) << '\n';
		
		delete [] candy;
	}
	
	return 0;
}
