#include <iostream>
#include <vector>
#include <utility>
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
	
	int testCase;
	
	int length; // require length
	int l, r; // input buffer
	vector< pair<int, int> > list; // total segments
	vector< pair<int, int> > ans; // answer segments
	list.reserve(100000);
	
	cin >> testCase;
	while(testCase--)
	{
		list.clear();
		ans.clear();
		
		cin >> length;
		while(cin >> l >> r)
		{
			if(l == 0 && r == 0) break;
			list.emplace_back(l, r); // = list.push_back( pair<int,int>(l, r) );
		}
		
		// sort segments by the start point, small to big
		sort(list.begin(), list.end(), cmp);
		
		int current = 0; // current position
		int index = 0;
		int maxIndex = -1; // the index of the segment which has the largest end point
		int maxRight = -1; // the max end point
		const int size = list.size();
		
		
		while(current < length)
		{
			// find the largest end point of the segments whose start point is smaller than curerent position
			while(index < size && list[index].first <= current){
				if(list[index].second > maxRight){
					maxRight = list[index].second;
					maxIndex = index;
				}
				index++;
			}
			
			if(maxIndex == -1) break; // there is no suitable segment
			
			ans.push_back(list[maxIndex]);
			
			// update the current position
			current = maxRight;
			
			// reset maxIndex
			maxIndex = -1;
		}
		
		
		// output
		if(current >= length){
			cout << ans.size() << '\n';
			for(auto p : ans){
				cout << p.first << " " << p.second << '\n';
			}
		}
		else{
			cout << "0\n";
		}
		
		// output a blank line between each cases
		if(testCase > 0) cout << '\n';
	}
	return 0;
}
