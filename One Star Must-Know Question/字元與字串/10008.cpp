#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;


int cnt[26] = {0};
char ch[26] = {	'A', 'B', 'C', 'D', 'E',
				'F', 'G', 'H', 'I', 'J',
				'K', 'L', 'M', 'N', 'O',
				'P', 'Q', 'R', 'S', 'T',
				'U', 'V', 'W', 'X', 'Y', 'Z'};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	int n;
	string str;
	
	cin >> n;
	cin.ignore();
	
	while(n){
		n--;
		
		getline(cin, str);
		for(char ch : str){
			if(isalpha(ch)){
				ch = toupper(ch);
				cnt[ ch - 'A' ]++;
			}
		}
	}
	
	// bubble sort, decending
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < 26-i-1; j++){
			if(cnt[j] < cnt[j+1]){
				swap(cnt[j], cnt[j+1]);
				swap(ch[j], ch[j+1]);
			}
		}
	}
	
	for(int i = 0; i < 26; i++){
		if(cnt[i] == 0)
			break;
		
		cout << ch[i] << " " << cnt[i] << '\n';
	}
	
	
	return 0;
}
