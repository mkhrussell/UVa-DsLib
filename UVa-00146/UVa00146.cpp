/*
UVa problem # 146 - ID Codes
URL: https://uva.onlinejudge.org/external/1/146.html
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	while (true)
	{
		string line;
		getline(cin, line);
		if (line == "#") break;
		
		if (std::next_permutation(line.begin(), line.end()))
		{
			cout << line << endl;
		}
		else
		{
			cout << "No Successor" << endl;
		}
	}

	return 0;
}