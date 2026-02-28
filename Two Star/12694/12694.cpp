#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Data{
	public:
		Data() = default;
		Data(int s, int e)
		{
			start = s;
			end = e;
		}
		
		int start;
		int end;
};

bool cmp(const Data a, const Data b) {
    return a.end < b.end;
}

int main()
{
	int day;
	cin >> day;
	while(day)
	{
		int start, end;
		vector<Data> list;
		
		//	input and store data into list
		while(cin >> start >> end)
		{
			if(start == 0 && end == 0)
				break;
			
			list.push_back(Data(start, end));
		}
		
		//	sort
		sort(list.begin(), list.end(), cmp);
		
		int event = 1;
		
		//	把clock的初始值設為「結束時間最早的事件」的結束時間
		int clock = list[0].end;
		for(int i = 1; i < list.size(); i++)
		{
			if(list[i].start >= clock)
			{
				clock = list[i].end;
				event++;
			}
		}
		
		cout << event << '\n';
		day--;
	}
	return 0;
}
