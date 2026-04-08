#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double p, q, r, s, t, u; // equation coefficient

// get the value of equation
double equation(const double& x){
	return p * exp((-x)) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

// use binary search to get a close answer
// big to small
double binarySearch(double left, double right){
	double mid;
	double value;
	
	// run 50 times to close the answer  
	for(int i = 0; i < 50; i++)
	{
		mid = (left + right) / 2;
		value = equation(mid);
		
		if(value > 0) left = mid;
		else right = mid;
	}
	
	return mid;
}



int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	
	double left, right; // value of 0.0 and 1.0
	while(cin >> p >> q >> r >> s >> t >> u)
	{
		left = equation(0.0);
		if(fabs(left) < 1e-9){
			// special case
			cout << "0.0000\n";
			continue;
		}
		
		right = equation(1.0);
		if(fabs(right) < 1e-9){
			// special case
			cout << "1.0000\n";
			continue;
		}
		
		if(left > 0.0 && right < 0.0){
			cout <<  fixed << setprecision(4) << binarySearch(0.0, 1.0) << '\n';
		}
		else{
			cout << "No solution\n";
		}
	}
	return 0;
}
