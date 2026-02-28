#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define NUMBER_RANGE 1000001 // 1000000 + 1

//	合數表
bool composite[NUMBER_RANGE] = {false};

//	紀錄到目前的數字，有幾個digits prime
int digits_count[NUMBER_RANGE] = {0};

int sum_of_digits(int n)
{
	int sum = 0;
	do{
		sum += n % 10;
		n /= 10;
	}while(n > 0);
	
	return sum;
}

void setPrimeList(void)
{
	composite[0] = composite[1] = true;
	
	for(int i = 2; i <= sqrt(NUMBER_RANGE); i++)
	{
		if(composite[i] == false)
		{
			for(int j = (NUMBER_RANGE-1) / i; j >= i; j--)
				if(composite[j] == false)
					composite[i * j] = true;
			
			if(composite[ sum_of_digits(i) ] == false)
				digits_count[i] = digits_count[i-1] + 1;
			else
				digits_count[i] = digits_count[i-1];
		}
		else
			digits_count[i] = digits_count[i-1];
	}
	
	//	已經建立合數表，處理剩下的digits prime list
	for(int i = sqrt(NUMBER_RANGE) + 1; i < NUMBER_RANGE; i++)
	{
		if(composite[i] == false)
		{
			if(composite[ sum_of_digits(i) ] == false)
				digits_count[i] = digits_count[i-1] + 1;
			else
				digits_count[i] = digits_count[i-1];
		}
		else
			digits_count[i] = digits_count[i-1];
	}	
}

int main()
{
	setPrimeList();
	
	int test_case;
	scanf("%d", &test_case);
	
	while(test_case)
	{
		int lower, upper;
		scanf("%d%d", &lower, &upper);
		
		//	注意digits_count是計算到當前數字有幾個digits prime
		//	所以lower需要-1
		printf("%d\n", digits_count[upper] - digits_count[lower - 1]);
		test_case--;
	}
	
	return 0;
}
