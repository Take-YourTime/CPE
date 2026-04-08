#include <iostream>
#include <cmath>
using namespace std;


const int RANGE = 32000; // the range of array
const long long int LIMIT = (long long int)2147483647; // the limit of number when building list

long long int digit[RANGE];			// index: number, value: the sequence length of 123...index
long long int digitLength[RANGE];	// index: number, value: the sum of digit[1] + digit[2] + ... + digit[index]

int arrSize; // max size of digit[] and digitLength[]


// return digit number of n
// e.g. getDigit(10) = 2, getdigit(111) = 3
int getDigit(const int& n)
{
	// return log10(n) + 1e-12 + 1; // 可能有精度問題
	if (n >= 10000) return 5;
    else if (n >= 1000) return 4;
    else if (n >= 100) return 3;
    else if (n >= 10) return 2;
    else return 1;
}


// build up digit[] and digitlength[]
void setList(void)
{
	digitLength[0] = 0;
	digit[0] = 0;
	
	for(int i = 1; i <= 9; i++){
		digitLength[i] = digitLength[i-1] + i;
		digit[i] = i;
	}
	
	int number = 10;
	long long int digitCount = 9; // the digits of "number", e.g. 10's digitCount is 2
	
	while(true){
		digitCount += getDigit(number);
		
		digit[number] = digitCount;
		digitLength[number] = digitLength[number-1] + digitCount;
		
		if(digitLength[number] > LIMIT) break;
		number++;
	}
	
	arrSize = number;
}


// to find the "index" that digitLength[index] is the biggest number that is smaller than "key"
int binarySearchIndex(int left, int right, const long long int& key)
{
	if(left > right) return right;
	
	int mid = (left + right) / 2;
	
	if(key < digitLength[mid]){			return binarySearchIndex(left, mid-1, key);		}
	else if(key > digitLength[mid]){	return binarySearchIndex(mid+1, right, key);	}
	else{	return mid-1;	} // key = digitLength[mid], but we need digitLength[index] is smaller than "key", so "return mid-1" rather than "return mid"
}

// to find the "index" that digit[index] is the smallest number that is bigger than length
int binarySearchDigit(int left, int right, const long long int& length)
{
	if(left > right) return left;
	
	int mid = (left + right) / 2;
	
	if(length < digit[mid]) return binarySearchDigit(left, mid-1, length);
	else if(length > digit[mid]) return binarySearchDigit(mid+1, right, length);
	else return mid;
}


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	// building up list
	setList();
	
	long long int n; // input number
	int testCase;
	cin >> testCase;
	while(testCase--)
	{
		cin >> n; // e.g. n = 8, number sequenxe = "1 12 123 12"
		
		
		int index = binarySearchIndex(1, arrSize-1, n);	// the "index" that digitLength[index] is the biggest number which is smaller than "n"
														// e.g. 1 12 123 12 -> consume 1 12 123, so "index" is 3
														
		int length = n - digitLength[ index ];	// the rest digit length of sequence that is 123...k
												// e.g. "1 12 123 12" - "1 12 123" = "12", so "length" = 2
		
		// we get the rest part length, and it is a sequence from 1 to k
		// so, we can find k or a number is bigger but close to k from digit[] accroading to "length"
		
		
		int lastNumber = binarySearchDigit(0, index+1, length); // use binary search in digit[] to find "k", we name it "lastNumber" here
		
		int deleteDigit =  digit[lastNumber] - length;	// maybe the request index is not the end "lastNumber"
														// e.g. lastNumber is 143, but we want to ouput 4, 
														// so 143 - 14, we need to delete 1 digit
		while(deleteDigit--){ // ignore redundant digit
			lastNumber /= 10;
		}
		
		
		// output
		cout << lastNumber % 10 << '\n';
	}
	return 0;
}
