#include <iostream>
using namespace std;

int main()
{
	long long int lower, upper;
	while(cin >> lower >> upper)
	{
		if(lower == 0 && upper == 0)
			break;
		
		lower /= 5;
		upper /= 5;
		
		cout << upper - lower + 1 << '\n';
	}
	return 0;
}
