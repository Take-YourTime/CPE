#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(const pair<char, int>& a, const pair<char, int>& b)
{
	return a.second < b.second;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	string str;
	
	bool isfirst = true;
	
	while(getline(cin, str))
	{	
		if(isfirst == false){
			cout << '\n';
		}
		else{
			isfirst = false;
		}
		
		map<char, int> dictionary;
		
		for(char ch : str){
			if(dictionary.find(ch) == dictionary.end()) dictionary[ch] = 1;
			else dictionary[ch]+=1;
		}
		
		
		vector< pair<char, int> > list;
		//	turn "map" to "vector"
		for(auto it = dictionary.rbegin(); it != dictionary.rend(); it++){
			list.push_back(*it);
		}
		
		//	stable sort - ascending
		stable_sort(list.begin(), list.end(), cmp);
		
		for(int i = 0; i < list.size(); i++){
			cout << int(list[i].first) << " " << list[i].second << '\n';
		}
	}
	return 0;
}
