#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	int test_case;
	cin >> test_case;
	while(test_case--)
	{
		cin >> str;
		if(str.size() == 5){
			cout << 3 << '\n';
		}
		else{
			int count = 0;
			if(str[0] == 'o') count++;
			if(str[1] == 'n') count++;
			if(str[2] == 'e') count++;
			
			if(count >= 2)	cout << 1 << '\n';
			else cout << 2 << '\n';
		}
	}
	return 0;
}
