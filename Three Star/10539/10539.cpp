#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

//long long int UPPER_RANGE = 1000000000000; //	10^12
const int NUMBER_RANGE = 1000000;

bool composite[NUMBER_RANGE] = { false };
vector<long long int> almost_prime;

void setPrimeList(void)
{
	composite[0] = true;
	composite[1] = false;

	for(int i = 2; i <= sqrt(NUMBER_RANGE); i++)
	{
		if(composite[i] == false)
		{
			for(int j = (NUMBER_RANGE-1) / i; j >= i; j--)
				if(composite[j] == false)
					composite[i * j] = true;
			
			for(long long int j = i * i; j < UPPER_RANGE; j *= i)
				almost_prime.push_back(j);
		}
	}
	
	for(long long int i = sqrt(NUMBER_RANGE); i < NUMBER_RANGE; i++)
	{
		if(composite[i] == false)
			for(long long int j = i * i; j < UPPER_RANGE; j *= i)
				almost_prime.push_back(j);
	}
}

//	find the index which value in almost_prime[index] is between lower and upper
int binary_search(int left, int right, long long int lower, long long int upper)
{
	//	no found
	if(right < left)
	{
		return -1;
	}
		
	int mid = (left + right) / 2;
	
	//	found
	if(almost_prime[mid] >= lower && almost_prime[mid] <= upper)
		return mid;
	else
	{
		if(almost_prime[mid] < lower)
			return binary_search(mid + 1, right, lower, upper);
		else
			return binary_search(left, mid - 1, lower, upper);
	}
}

int main()
{
	//	find prime and almost-prime
	setPrimeList();
	
	//	sort
	sort(almost_prime.begin(), almost_prime.end());
	
	int test_case;
	cin >> test_case;

	long long int lower, upper;
	while (test_case)
	{
		cin >> lower >> upper;
		
		int lower_index = binary_search(0, almost_prime.size() - 1, lower, upper);
		int upper_index = lower_index;
		
		
		if(lower_index == -1)
			cout << 0 << '\n';
		else
		{
			while(almost_prime[lower_index] >= lower && lower_index >= 0)
				lower_index--;
			
			while(almost_prime[upper_index] <= upper && upper_index < almost_prime.size())
				upper_index++;
			
			cout << upper_index - lower_index - 1 << '\n';
		}
			
		
		test_case--;
	}
	return 0;
}
