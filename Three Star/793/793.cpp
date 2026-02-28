#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class PC {
public:
	vector<int> connect;
};

PC* pc;

bool find(vector<int> link, int key, vector<bool>& search)
{
	for (int i = 0; i < link.size(); i++)
	{
		if (!search[ link[i] ])
		{
			search[ link[i] ] = true;
			if (link[i] == key)
				return true;
			else if ( find(pc[ link[i] ].connect, key, search) )
				return true;
		}
	}

	return false;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout.sync_with_stdio(false);

	int test_case;
	cin >> test_case;
	cin.ignore();

	while (test_case)
	{
		int n;
		cin >> n;
		n += 1;

		int success = 0;
		int wrong = 0;

		pc = new PC[n];
		string command_line;
		char command;
		int pc1, pc2;

		cin.ignore();
		while (getline(cin, command_line) && !command_line.empty())
		{
			istringstream iss(command_line);
			iss >> command >> pc1 >> pc2;

			switch (command)
			{
			case 'c':
				if (pc1 != pc2)
				{
					pc[pc1].connect.push_back(pc2);
					pc[pc2].connect.push_back(pc1);
				}
				
				break;
			case 'q': {
				if (pc1 == pc2)
					success++;
				else
				{
					vector<bool> search(n, false);

					bool isconnect = find(pc[pc1].connect, pc2, search);

					if (isconnect)
						success++;
					else
						wrong++;
				}

				break;
			}
			default:
				cout << "Wrong command\n";
				break;
			}
		}

		test_case--;

		cout << success << "," << wrong << '\n';
		if (test_case)
			cout << '\n';
		
		delete[] pc;
	}
	return 0;
}
