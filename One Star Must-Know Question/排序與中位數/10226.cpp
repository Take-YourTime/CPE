#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	int test_case;
	string str;
	
	cin >> test_case;
	cin.ignore();
	getline(cin, str); //	input ignore
	
	
	map<string, double> dictionary;
	
	while(test_case)
	{
		// initialization
		dictionary.clear();
		double count = 0.0;
		
		while(getline(cin, str))
		{
			if(str.size() == 0)	break;
			
			dictionary[str] += 1.0;	
			count += 1.0;
		}
		
		for(auto it : dictionary){
			cout << it.first << " " << fixed << setprecision(4) << it.second * 100.0 / count << '\n';
		}
		
		if(test_case > 1) cout << '\n';
		
		test_case--;
	}
	return 0;
}
