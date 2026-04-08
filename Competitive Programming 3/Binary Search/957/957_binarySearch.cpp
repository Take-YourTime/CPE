#include <iostream>
#include <vector>
using namespace std;

vector<int> election; // election list

// binary search to get the element's index which is smallest of the number in election list that are bigger than key
int binarySearch(const int& key, int left, int right)
{
	if(left > right) return left;
	
	int mid = (left + right) / 2;
	
	if(key < election[mid]) return binarySearch(key, left, mid-1);
	else if(election[mid] < key) return binarySearch(key, mid+1, right);
	else return mid;
}


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	int period; // counting period
	int pope; // pope number
	int n; // input buffer
	
	while(cin >> period)
	{
		election.clear();
		
		// input election years
		cin >> pope;
		while(pope--)
		{
			cin >> n;
			election.push_back(n);
		}
		
		// initialization
		int firstElection;
		int lastElection;
		int max = 0; // the max pope number in the period
		const int size = election.size();
		
		for(int i = 0; i < size - max; i++)
		{
			// binary search
			int j = binarySearch(election[i] + period, i, size-1);
			
			// save the largest pope number, first election year and last election year
			if(j-i > max){
				max = j-i;
				firstElection = election[i];
				lastElection = election[j-1];
			}
		}
		
		cout << max << " " << firstElection << " " << lastElection << '\n';
	}
	return 0;
}
