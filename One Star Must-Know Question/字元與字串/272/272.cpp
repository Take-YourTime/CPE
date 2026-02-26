#include <iostream>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	char ch;
	bool isFirst = true;
	
	while(cin.get(ch)){
		if(ch == '\"' && isFirst){
			cout << "``";
			isFirst = false;
		}
		else if (ch == '\"'){
			cout << "\'\'";
			isFirst = true;
		}
		else{
			cout << ch;
		}
	}
	return 0;
}
