#include <iostream>
#include <string>
using namespace std;

int main()
{
	string mode;
	int sum = 0;
	int donate;
	
	int test_case;
	cin >> test_case;
	while(test_case--)
	{
		cin >> mode;
		if(mode == "donate"){
			cin >> donate;
			sum += donate;
		}
		else{
			cout << sum << '\n';
		}
	}
	return 0;
}
