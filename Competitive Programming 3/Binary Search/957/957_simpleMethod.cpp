#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	int period; // counting period
	int pope; // pope number
	vector<int> election; // election list
	
	while(cin >> period)
	{
		election.clear();
		int n; // input buffer
		
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
			int j = i+1;
			int currentYear = election[i];
			
			// get the pope number from current election()
			while(election[j] < currentYear + period && j < size){
				j++;
			}
			
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
