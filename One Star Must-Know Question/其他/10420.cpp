#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	int test_case;
	cin >> test_case;
	
	string country, name;
	
	map<string, int> dictionary;
	
	while(test_case)
	{
		test_case--;
		cin >> country;
		cin.ignore();
		getline(cin, name);
		
		dictionary[country] += 1;
	}
	
	for(auto it = dictionary.begin(); it != dictionary.end(); it++){
		cout << it->first << " " << it->second << '\n';
	}
	return 0;
}
