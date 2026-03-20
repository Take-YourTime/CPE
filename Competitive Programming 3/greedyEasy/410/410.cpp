#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

// WATCHOUT!  The data set in the uDebug are not correct.

bool cmp(const int& a, const int& b){
	return a > b;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	int chambers; // the number of chamber 
	int specimens; // the number of specimen
	int mass[10]; // the mass of each specimen
	
	int testCase = 1;
	
	while(cin >> chambers >> specimens)
	{
		double sum = 0.0; // buffer for sum up
		
		// input
		for(int i = 0; i < specimens; i++){
			cin >> mass[i];
			sum += mass[i];
		}
		
		double avg = sum / double(chambers); // average mass sum of each chamber
		
		// sort mass array, big to small
		sort(mass, mass + specimens, cmp);
		
		// add 0 mass to the end of array to fill all the champers
		while(specimens < chambers * 2) {
			mass[specimens] = 0;
			specimens++;
		}
		
		
		double imbalance = 0.0;
		
		// calculate imbalance and output
		cout << "Set #" << testCase << '\n';
		for(int i = 0; i < chambers; i++)
		{	
			cout << ' ' << i << ':';
			
			if(mass[i]) cout << ' ' << mass[i];
			if(mass[specimens - 1 - i]) cout << ' ' << mass[specimens - 1 - i];
			
			cout << '\n';
			
			// update
			imbalance += abs(mass[i] + mass[specimens - 1 - i] - avg);
		}
		cout << "IMBALANCE = " << fixed << setprecision(5) << imbalance << "\n\n";
		
		testCase++;
	}
	return 0;
}
