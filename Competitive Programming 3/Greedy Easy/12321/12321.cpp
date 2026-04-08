// This question is similar to uva 10020
// input: road length, gas station number, position and radius of each gas station
// output: the number of gas station to eliminate

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.first < b.first;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	int length, gasStations;
	int x, r; // input buffer
	
	vector< pair<int, int> > list;
	list.reserve(100000);
	
	while(cin >> length >> gasStations)
	{
		if(length == 0 && gasStations == 0) break;
		
		list.clear();
		
		while(gasStations--)
		{
			cin >> x >> r;
			list.push_back(pair<int, int>(x - r, x + r));
		}
		
		sort(list.begin(), list.end(), cmp);
		
		int current = 0; // current position
		int count = 0; // chosen gas station number
		int index = 0; 
		int maxIndex = -1;
		int maxRight = -1;
		gasStations = list.size();
		
		while(current < length)
		{
			while(index < gasStations && list[index].first <= current){
				if(list[index].second > maxRight){
					maxRight = list[index].second;
					maxIndex = index;
				}
				index++;
			}
			
			if(maxIndex == -1) break;
			
			// update
			current = maxRight;
			count++;
			
			// reset
			maxIndex = -1;
		}
		
		if(current >= length){
			cout << gasStations - count << '\n';
		}
		else{
			cout << "-1\n";
		}
	}
	return 0;
}
