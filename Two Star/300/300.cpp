#include <iostream>
#include <string>
using namespace std;

int main()
{
	int test_case;
	cin >> test_case;
	cout << test_case << '\n';
	cin.ignore();
		
	string name[20] = {	"imix",
						"ik",
						"akbal",
						"kan",
						"chicchan",
						"cimi",
						"manik",
						"lamat",
						"muluk",
						"ok",
						"chuen",
						"eb",
						"ben",
						"ix",
						"mem",
						"cib",
						"caban",
						"eznab",
						"canac",
						"ahau" };
	
	string str;
	while(test_case)
	{
		getline(cin, str);
		int index = 0;
		
		int h_day = 0, h_month = 0, h_year = 0;
		string month;
		
		//	calculate day
		while(str[index] != '.')
		{
			h_day *= 10;
			h_day += int(str[index]) - int('0');
			index++;
		}
		
		index += 2;
		
		//	calculate month
		while(str[index] != ' ')
		{
			month.push_back(str[index]);
			index++;
		}
		
		if(month == "pop")
			h_month = 1;
		else if(month == "no")
			h_month = 2;
		else if(month == "zip")
			h_month = 3;
		else if(month == "zotz")
			h_month = 4;
		else if(month == "tzec")
			h_month = 5;
		else if(month == "xul")
			h_month = 6;
		else if(month == "yoxkin")
			h_month = 7;
		else if(month == "mol")
			h_month = 8;
		else if(month == "chen")
			h_month = 9;
		else if(month == "yax")
			h_month = 10;
		else if(month == "zac")
			h_month = 11;
		else if(month == "ceh")
			h_month = 12;
		else if(month == "mac")
			h_month = 13;
		else if(month == "kankin")
			h_month = 14;
		else if(month == "muan")
			h_month = 15;
		else if(month == "pax")
			h_month = 16;
		else if(month == "koyab")
			h_month = 17;
		else if(month == "cumhu")
			h_month = 18;
		else if(month == "uayet")
			h_month = 19;
		else
		{
			cout << month << " Wrong!\n";
			exit(EXIT_FAILURE);
		}
		
		index++;
		
		//	calculate year
		while(index < str.size())
		{
			h_year *= 10;
			h_year += int(str[index]) - int('0');
			index++;
		}
		
		long long int pass = h_day + (h_month - 1) * 20 + h_year * 365;
		
		int t_year = pass / 260;
		pass %= 260;
		
		int t_day = pass % 13 + 1;
		
		int t_month = pass % 20;
		month = name[t_month];
		
		cout << t_day << " " << month << " " << t_year << '\n';
		test_case--;
	}
	return 0;
}
