#include <iostream>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	int test_case;
	cin >> test_case;
	
	int length;
	int train[55] = {0};
	
	while(test_case)
	{
		test_case--;
		cin >> length;
		
		for(int i = 0; i < length; i++)
			cin >> train[i];
		
		int count = 0;
		bool noOperation;
		
		for(int i = 0; i < length - 1; i++)
		{
			noOperation = true;
			for(int j = 0; j < length - i - 1; j++)
			{
				if(train[j] > train[j+1]){
					swap(train[j], train[j+1]);
					count++;
					if(noOperation) noOperation = false;
				}
			}
			
			if(noOperation)	break;
		}
		
		cout << "Optimal train swapping takes " << count << " swaps.\n";
	}
	return 0;
}
