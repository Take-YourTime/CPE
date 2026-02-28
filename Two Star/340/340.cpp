#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int number;
	int index = 1;
	while(cin >> number && number != 0)
	{
		cout << "Game " << index << ":\n";
		index++;
		
		int* key = new int[number];
		int* guess = new int[number];
		
		for(int i = 0; i < number; i++)
		{
			cin >> key[i];
		}
		
		
		while(true)
		{
			int correct = 0;
			int change = 0;
			bool* use = new bool[number];
			
			
			for(int i = 0; i < number; i++)
			{
				cin >> guess[i];
				if(guess[i] == key[i])
				{
					correct++;
					use[i] = true;
					guess[i] = -1;
				}
				else
					use[i] = false;
			}
			
			//	end program
			if(guess[0] == 0)
				break;
			
			for(int i = 0; i < number; i++)
			{
				if(guess[i] != -1)
				{
					for(int j = 0; j < number; j++)
					{
						if( use[j] == false && key[j] == guess[i])
						{
							use[j] = true;
							change++;
							break;
						}
					}
				}
			}
			
			cout << "    (" << correct << ',' << change << ")\n";
		}
	}
	return 0;
}
