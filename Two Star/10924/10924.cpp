#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cctype>
#define NUMBER_RANGE 100000
using namespace std;

//	合數表
bool composite[NUMBER_RANGE] = {false};

void setPrimeList(void)
{
	composite[0] = true;
	composite[1] = false;
	
	for(int i = 2; i <= sqrt(NUMBER_RANGE); i++)
	{
		if(composite[i] == false)
		{
			for(int j = (NUMBER_RANGE-1) / i; j >= i; j--)
				if(composite[j] == false)
					composite[i * j] = true;
		}
	
	}
}

int char_to_int(char ch)
{
	if(islower(ch))
		return int(ch) - int('a') + 1;
	else
		return int(ch) - int('A') + 27; // + 1 + 26
}

int main()
{
	setPrimeList();
	
	string str;
	
	while(!cin.eof() && cin >> str)
	{
		int count = 0;
		for(int i = 0; i < str.size(); i++)
		{
			count += char_to_int(str[i]);
		}
		
		cout << (composite[count] == true ? "It is not a prime word.\n" : "It is a prime word.\n");
	}
	return 0;
}
