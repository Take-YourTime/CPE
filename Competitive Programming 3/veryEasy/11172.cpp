#include <iostream>
using namespace std;

int main()
{
	int a, b;
	int test_case;
	cin >> test_case;
	while(test_case--)
	{
		cin >> a >> b;
		if(a > b)	cout << ">\n";
		else if(a == b)	cout << "=\n";
		else cout << "<\n";
	}
	return 0;
}
