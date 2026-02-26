#include <iostream>
#include <string>
#include <map>
#include <cctype>
using namespace std;

class Pair{
	public:
		int line;
		int index;
		
		Pair() = default;
		Pair(int l, int i){
			line = l;
			index = i;
		};
		
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	
	string str[3];
	str[1] = "qwertyuiop[]\\";
	str[2] = "asdfghjkl;\'";
	str[3] = "zxcvbnm,./";
	
	map<char, Pair> dictionary;
	
	// build dictionary
	/*
	for(int i = 0; i < str[3].size(); i++)
	{
		cout << "dictionary[\'" << str[3][i] << "\'] = Pair(3, " << i <<");" << '\n';
	}
	*/
	
	
	dictionary['`'] = Pair(0, 0);
	dictionary['1'] = Pair(0, 1);
	dictionary['2'] = Pair(0, 2);
	dictionary['3'] = Pair(0, 3);
	dictionary['4'] = Pair(0, 4);
	dictionary['5'] = Pair(0, 5);
	dictionary['6'] = Pair(0, 6);
	dictionary['7'] = Pair(0, 7);
	dictionary['8'] = Pair(0, 8);
	dictionary['9'] = Pair(0, 9);
	dictionary['0'] = Pair(0, 10);
	dictionary['-'] = Pair(0, 11);
	dictionary['='] = Pair(0, 12);
	
	dictionary['q'] = Pair(1, 0);
	dictionary['w'] = Pair(1, 1);
	dictionary['e'] = Pair(1, 2);
	dictionary['r'] = Pair(1, 3);
	dictionary['t'] = Pair(1, 4);
	dictionary['y'] = Pair(1, 5);
	dictionary['u'] = Pair(1, 6);
	dictionary['i'] = Pair(1, 7);
	dictionary['o'] = Pair(1, 8);
	dictionary['p'] = Pair(1, 9);
	dictionary['['] = Pair(1, 10);
	dictionary[']'] = Pair(1, 11);
	dictionary['\\'] = Pair(1, 12);
	
	dictionary['a'] = Pair(2, 0);
	dictionary['s'] = Pair(2, 1);
	dictionary['d'] = Pair(2, 2);
	dictionary['f'] = Pair(2, 3);
	dictionary['g'] = Pair(2, 4);
	dictionary['h'] = Pair(2, 5);
	dictionary['j'] = Pair(2, 6);
	dictionary['k'] = Pair(2, 7);
	dictionary['l'] = Pair(2, 8);
	dictionary[';'] = Pair(2, 9);
	dictionary['\''] = Pair(2, 10);
	
	dictionary['z'] = Pair(3, 0);
	dictionary['x'] = Pair(3, 1);
	dictionary['c'] = Pair(3, 2);
	dictionary['v'] = Pair(3, 3);
	dictionary['b'] = Pair(3, 4);
	dictionary['n'] = Pair(3, 5);
	dictionary['m'] = Pair(3, 6);
	dictionary[','] = Pair(3, 7);
	dictionary['.'] = Pair(3, 8);
	dictionary['/'] = Pair(3, 9);
	
	
	string input;
	getline(cin, input);
	for(char ch : input){
		if(ch == ' ')
			cout << " ";
		else{
			if(isupper(ch)) ch = tolower(ch);
			
			Pair position = dictionary[ch];
			cout << str[position.line][position.index-2];
		}
	}
	cout << '\n';
	return 0;
}
