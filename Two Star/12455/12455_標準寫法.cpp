/*
	B113040045 許育菖
	2024/03/11
	This program is to know whethever we can get the specific length of bar from several given bars.\
	使用動態規劃
*/

#include <iostream>
#include <vector>
using namespace std;

//	Whethever can get the final_length from the composition of the elements in bar_length
bool CanGetLength(vector<int>& bar_length, int final_length)
{
	//	the numbers that can be composed
	bool compose[final_length + 1] = {0};
	compose[0] = true;
	for(int i = 0; i < bar_length.size(); i++)
		compose[ bar_length[i] ] = true;
	
	//	store numebr temply
	vector<int> canBeComposed;
	
	for(int i = 0; i < bar_length.size(); i++)
	{
		//	the length of canBeComposed
		int canBeComposed_length = canBeComposed.size();
		
		for(int j = canBeComposed_length - 1; j >= 0; j--)
		{
			int number = bar_length[i] + canBeComposed[j];
			
			if(number < (final_length + 1) && compose[number] == false)
			{
				canBeComposed.push_back(number);
				compose[number] = true;
			}
		}
		
		canBeComposed.push_back(bar_length[i]);
	}
	
	//	can get final_length → return true
	return (compose[final_length] ? true : false);
}

int main()
{
	//	0 < = test_case <= 50
	int test_case;
	cin >> test_case;
	
	while(test_case)
	{
		bool findAnswer = false;
		
		/* input */
		//	final length of bar
		int final_length;
		cin >> final_length;
		
		//	number of bars
		int number;
		cin >> number;
		
		//	length of each bar
		vector<int> bar_length;
		for(int i = 0; i < number; i++)
		{
			int n;
			cin >> n;
			if(n < final_length)
				bar_length.push_back(n);
		}
		
		//	Special case, final length = 0
		if(final_length == 0)
			cout << "YES\n";
		else if(CanGetLength(bar_length, final_length))
			cout << "YES\n";
		else
			cout << "NO\n";
		
		test_case--;
	}
	return 0;
}