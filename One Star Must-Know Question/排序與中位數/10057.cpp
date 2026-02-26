#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000005];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	int numbers;
	
	while(cin >> numbers)
	{
		for(int i = 0; i < numbers; i++){
			cin >> arr[i];
		}
		
		sort(arr, arr+numbers);
		
		int middle = (numbers-1) / 2;
		int key = arr[middle]; // middle point
		int count = 1;
		
		// find identical number -- left
		for(int left = middle - 1; left >= 0; left--){
			if(arr[left] == key) count++;
			else break;
		}
		
		// find identical number -- right
		if(numbers % 2 == 0){
			int key2 = arr[middle+1];
			count++;
			
			for(int right = middle + 2; right < numbers; right++){
				if(arr[right] == key2) count++;
				else break;
			}
		}
		else{
			for(int right = middle + 1; right < numbers; right++){
				if(arr[right] == key) count++;
				else break;
			}
		}
			
		
		cout << key << " " << count << " ";
		if(numbers % 2 == 0) cout << arr[middle+1] - arr[middle] + 1 << '\n';
		else	cout << 1 << '\n';
	}
	return 0;
}

