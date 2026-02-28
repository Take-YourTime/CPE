#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#define NUMBER_RANGE 301 // 300 + 1
using namespace std;


//	將參數a、b以字典序大小進行比較，由小到大排序
bool comp(int a, int b)
{
	stringstream ss1;
	stringstream ss2;
	ss1 << a;
	ss2 << b;
	return ss1.str() < ss2.str();
}


/*==========global variable==========*/

//	質數表中的index  目標數字  (組成的數字列表)
bool dp[140][1000 + 1][14];

//	answer
vector<int> ans(14);

//	合數表
bool composite[NUMBER_RANGE] = { false };

//	prime list
vector<int> prime;

int large_prime;
/*===================================*/


void setPrimeList(void)
{
	composite[0] = composite[1] = true;
	
	//	處理2的倍數
	prime.push_back(2);
	for (int j = 2; j <= (NUMBER_RANGE - 1) / 2; j++)
	{
		composite[2 * j] = true;
	}

	for (int i = 3; i < sqrt(NUMBER_RANGE); i++)
	{
		if (composite[i] == false)
		{
			//	3以上的質數可以重複計算兩次，因此建立時直接push兩次到質數表中
			prime.push_back(i);
			prime.push_back(i);
			for (int j = i; j <= (NUMBER_RANGE - 1) / i; j++)
			{
				composite[i * j] = true;
			}
		}
	}

	for (int i = sqrt(NUMBER_RANGE) + 1; i < NUMBER_RANGE; i++)
	{
		if (composite[i] == false)
		{
			//	3以上的質數可以重複計算兩次，因此建立時直接push兩次到質數表中
			prime.push_back(i);
			prime.push_back(i);
		}
	}
	
	large_prime = prime[prime.size() - 1];
}

//	index: index of "prime" list.
//	sum: the current sum.
//	prime_number: the number of chosen primes.
//	key: 目標值
//	compose_number: 要以幾個數來組成
bool find(int index, int sum, int prime_number, int key, int compose_number)
{
	if (index == prime.size())
		return false;
	else if (prime_number == compose_number)
	{
		if (sum == key)
			return true;
		else
			return false;
	}
	else if (sum >= key)
		return false;
	else if (dp[index][sum][prime_number] == false)
		return false;
	
	ans[prime_number] = prime[index];

	if (find(index + 1, sum + prime[index], prime_number + 1, key, compose_number))	//	加下一個質數
		return true;
		
	if (find(index + 1, sum, prime_number, key, compose_number))	//	更換當前的數字
		return true;

	//	執行到這裡時，表示以當前情況繼續執情都無法實現目標
	dp[index][sum][prime_number] = false;

	return false;
}

int main()
{
	//	加速輸入輸出
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	setPrimeList();

	sort(prime.begin(), prime.end(), comp);	//	將prime list按照字典序大小進行排序

	int key, n;
	int test_case = 0;

	while (cin >> key >> n && (key != 0 && n != 0))
	{
		test_case++;
		
		//	n必須小於質數表的大小
		if (key > large_prime * n)
		{
			cout << "CASE " << test_case << ":\n";
			cout << "No Solution.\n";
			continue;
		}
		
		memset(dp, true, sizeof(dp)); // 將dp初始值設為true

		cout << "CASE " << test_case << ":\n";

		if ( find(0, 0, 0, key, n) )
		{
			if(n > 1)
			{
				cout << ans[0];
				for (int i = 1; i < n; i++)
					cout << '+' << ans[i];
				cout << '\n';
			}
			else
				cout << ans[0] << '\n';	
		}
		else
		{
			cout << "No Solution.\n";
		}
	}
	return 0;
}
