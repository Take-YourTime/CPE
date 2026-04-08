#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

int books[10005]; // the cost of books
bool selection[10005]; // true -> the elelment of books that has been chosen

bool binarySearch(int left, int right, const int& key)
{
	if(left > right) return false;
	
	int mid = (left + right) / 2;
	
	if(key < books[mid]) 		return binarySearch(left, mid-1, key);
	else if(key > books[mid])	return binarySearch(mid+1, right, key);
	else if(selection[mid] == false){ // key = books[mid] and it is not the same book
		selection[mid] = true;
		return true; 
	}
	else return false;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	int number; // books number
	int total; // total money
	while(cin >> number)
	{
		for(int i = 0; i < number; i++){
			cin >> books[i];
			selection[i] = false;
		}
		
		
		// sorting: small to big
		sort(books, books + number);
		
		cin >> total;
				
		int book1, book2; // the book cost to output
		int requestValue; // the request book cost, we need to find whether there is a book has the request cost by binary search
		int diff = INT_MAX; // cost difference between book1 and books
		
		for(int i = 0; i < number; i++) {
			if(selection[i]) continue;
			selection[i] = true;
			requestValue = total-books[i];
			
			// binary search to find the book has requestValue
			// and record the the two books that has minimal difference
			if(binarySearch(0, number-1, requestValue)){
				if(abs(requestValue - books[i]) < diff){
					diff = abs(requestValue - books[i]);
					book1 = books[i];
					book2 = requestValue;
				}
			}
		}
		
		if(book1 > book2) swap(book1, book2);
		
		cout << "Peter should buy books whose prices are " << book1 << " and " << book2 << ".\n\n";
	}
	return 0;
}
