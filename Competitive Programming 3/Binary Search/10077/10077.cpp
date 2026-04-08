#include <iostream>
using namespace std;

// compare fraction number, a/b v.s. x/y
int fractionCompare(const int& a, const int& b, const int& x, const int& y)
{
	if (a * y < x * b) return -1; 		// a / b is smaller than x / y
	else if(a * y == x * b) return 0;	// a / b is equal to x / y
	else return 1; 						// a / b is bigger than x / y
}

// nL: numerator of left fraction, dL: denominator of left fraction
// nL: numerator of right fraction, dL: denominator of right fraction
// numerator: the numerator of searching fraction
// denominator: the denominator of ssearching fraction
void binarySearch(int nL, int dL, int nR, int dR, const int& numerator, const int& denominator)
{
	int nMid = nL + nR; // numerator of middle fraction
	int dMid = dL + dR; // denominator of middle fraction
	
	int compareResult = fractionCompare(numerator, denominator, nMid, dMid);
	
	if(compareResult == -1){
		cout << 'L';
		binarySearch(nL, dL, nMid, dMid, numerator, denominator);
	}
	else if(compareResult == 0){
		return;
	}
	else{
		cout << 'R';
		binarySearch(nMid, dMid, nR, dR, numerator, denominator);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	const int numeratorLeft = 0, denominatorLeft = 1;	// the leftest fraction
	const int numeratorRight = 1, denominatorRight = 0;	// the rightest fraction
	
	int m, n;
	while(cin >> m >> n && (m != 1 || n != 1))
	{
		binarySearch(numeratorLeft, denominatorLeft, numeratorRight, denominatorRight, m, n);
		cout << '\n';
	}
	return 0;
}
