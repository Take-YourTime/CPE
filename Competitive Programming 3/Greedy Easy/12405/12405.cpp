// input: a 1*n map with crow-gruwing spot '.' or infertile region '#'
// output: the number of scarecrows to cover all crow-gruwing spots

#include <iostream>
using namespace std;

char map[105];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	int testCase;
	cin >> testCase;
	int size; // map size
	for(int index = 1; index <= testCase; index++)
	{
		cin >> size;
		for(int i = 0; i < size; i++){
			cin >> map[i];
		}
		
		int pos = 0; // current position
		int count = 0; //  Scarecrow count
		int lastScarecrow = -1; // the last scarecrow position
		
		
		while(true){
			// find a crow
			while(pos < size && map[pos] != '.') pos++;
			
			// check current positon is in the map or not
			if(pos >= size) break;
			
			// put a scarecrow at the next cell(pos+1)
			count++;
			lastScarecrow = pos+1;
			
			// skip 3 cell
			pos += 3;
		}
		
		// in this special case, the last cell is not cover, 
		// if it is a crop-growing spot, then we should add a scarecrow
		if(lastScarecrow == size-3 && map[size-1] == '.'){
			count++;
		}
		
		
		// output
		cout << "Case " << index << ": " << count << '\n';
	}
	return 0;
}
