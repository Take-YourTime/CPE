#include <iostream>
#include <string>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	string str1, str2;
	
	while(getline(cin, str1))
	{
		getline(cin, str2);

		int count1[26] = {0};
		int count2[26] = {0};
		
		for(char ch : str1){
			count1[ch-'a']++;
		}
		
		for(char ch : str2){
			count2[ch-'a']++;
		}
		
		for(int i = 0; i < 26; i++)
		{
			int times = min(count1[i], count2[i]);
			while(times--){
				cout << char('a'+i);
			}
		}
		cout << '\n';
	}
	return 0;
}
