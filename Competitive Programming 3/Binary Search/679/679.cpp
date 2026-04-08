#include <iostream>
using namespace std;


const int nodeNumber = 1 << 20 ;
//int tree[nodeNumber+5];  // tree index -> nodeValue, but we don't need to use this
int mapping[nodeNumber+5]; // map nodeValue -> tree index


/*
	   0
	 1   2
	3 4 5 6
	left = 2*i + 1
	right = 2*i + 2 
*/

// use DFS to set up each node
void setTreeNode(int index, int rootValue, int depth)
{
	if(index >= nodeNumber) return;
	
	//tree[index] = rootValue;
	mapping[rootValue] = index;
	
	setTreeNode(index * 2, rootValue + (1 << (depth-1)), depth+1); // left child
	setTreeNode(index * 2 + 1, rootValue + (1 << (depth-1)) * 2, depth+1); // right child
}


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);
	
	
	setTreeNode(1, 1, 1);
	
	int testCase;
	int depth, index;
	cin >> testCase;
	while(testCase--)
	{
		cin >> depth >> index;
		int position = (1 << (depth-1)) - 1 + index;
		cout << mapping[position] << '\n';
	}
	
	// end input, just ignore
	cin >> depth;
	return 0;
}
