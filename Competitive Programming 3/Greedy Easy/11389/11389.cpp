// input: driver number, max route length, hourly fee, and route length of each bus
// output: the overtime pay

// [STRATEGY]
// Sum up the smallest moring route and the largest evening route,
// and the second smalledt moring route and the second largest evening route, ... .
// Detect if the sum is overlimit, then save the overtime hours.
// Finally, calculate the overtime pay by the saving overtime hours.
#include <iostream>
#include <algorithm>
using namespace std;


int moring[10005];	// moring bus route length
int night[10005];	// evening bus route length

bool cmp(const int& a, const int& b)
{
	return a > b;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	int drivers;	// driver number
	int limit;		// the limit of max route length
	int fee;		// the hourly fee of overlimit
	
	while(cin >> drivers >> limit >> fee)
	{
		if(drivers == 0 && limit == 0 && fee == 0) break;
		
		// input route length
		for(int i = 0; i < drivers; i++){
			cin >> moring[i];
		}
		for(int i = 0; i < drivers; i++){
			cin >> night[i];
		}
		
		sort(moring, moring+drivers);		// sort moring route length small to big
		sort(night, night+drivers, cmp);	// sort evening route length big to small
		
		int count = 0; // overlimit hours
		int route;	// adding buffer
		for(int i = 0; i < drivers; i++){
			route = moring[i] + night[i];
			if(route > limit) count += route - limit;
		}
		
		cout << count * fee << '\n';
	}
	return 0;
}
