/*
	B113040045 許育菖
	2024/03/11
	This program is to know whethever we can get the specific length of bar from several given bars. 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//	let the boolean array plus 1
bool ArrayPlus(bool arr[], int arr_size)
{
	
	
	for(int i = 0; i < arr_size; i++)
	{
		if(arr[i] == 0)
		{
			arr[i] = 1;
			return true;
		}
		else
			arr[i] = 0;
	}
	
	return false;
}

//	Whethever can get the final_length from the composition of the elements in bar_length
bool CanGetLength(vector<int>& bar_length, int final_length, int the_min_length)
{
	//	the size of bar_length
	const int size = bar_length.size();
	
	//	the elements to pick in bar_length, this array works as a binary number
	bool pick[size] = {0};
	for(int i = 0; i < the_min_length; i++)
		pick[i] = 1;
	
	//	the sum of picked elements in bar_length
	int sum;
	
	do{
		sum = 0;
		for(int i = 0; i < size; i++)
		{
			if(pick[i] == true)
			{
				sum += bar_length[i];
			}
		}
		
		if(sum == final_length)
			return true;
	}while(ArrayPlus(pick, size));
	
	return false;
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
		
		//	sort
		sort(bar_length.begin(), bar_length.end());
		
		//	計算最多抽幾個出來
		int the_min_length = 1;
		int sum = 0;
		
		for(int i = bar_length.size() - 1; i >= 0; i++)
		{
			sum += bar_length[i];
			if(sum > final_length)
			{
				the_min_length = bar_length.size() - i;
				break;
			}
		}
		
		//	Special case, final length = 0
		if(final_length == 0)
			cout << "YES\n";
		else if(CanGetLength(bar_length, final_length, the_min_length))
			cout << "YES\n";
		else
			cout << "NO\n";
		
		test_case--;
	}
	return 0;
}
