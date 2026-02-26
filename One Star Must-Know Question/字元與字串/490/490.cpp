#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	char str[105][105];
	int index = 0;
	int max_length = 0;
	
	// input
	while(cin.getline(str[index], 105))
	{	
		if(strlen(str[index]) > max_length)
			max_length = strlen(str[index]);
		index++;
	}
	
	// output
	for(int j = 0; j < max_length; j++){
		for(int i = index-1; i >= 0; i--){
			if(j < strlen(str[i])){
				cout << str[i][j];
			}
			else
				cout << " ";
			
		}
		cout << '\n';
	}
	
	return 0;
}
