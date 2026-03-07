#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	int test_case;
	cin >> test_case;
	for(int index = 1; index <= test_case; index++)
	{
		cin >> a >> b >> c;
		if(a > b) swap(a, b);
		if(a > c) swap(a, c);
		if(b > c) swap(b, c);
		cout << "Case " << index << ": " << b << '\n';
	}
	return 0;
}
