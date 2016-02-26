/*
UVa Problem # 10038 - Jolly Jumpers
URL: https://uva.onlinejudge.org/external/100/10038.pdf

Critical input:

5 3 2 3 2 3
4 1 4 2 3
5 1 4 2 -1 6
1 1
2 1 2
4 5 5 5 5
5 10 8 6 4 2
4 1 4 3 1
4 3 1 5 2


Output:

Not jolly
Jolly
Not jolly
Jolly
Jolly
Not jolly
Not jolly
Jolly
Not jolly

*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
	int N;
	int diffs[3009];
	while (scanf("%d", &N) == 1)
	{		
		int prev;
		scanf("%d", &prev);
		for (int n = 1; n < N; n++)
		{
			int current;
			scanf("%d", &current);
			diffs[n-1] = std::abs(current - prev);

			prev = current;
		}

		std::sort(diffs, diffs + N - 1);

		bool isJolly = true;
		for (int i = 0; i < N - 1; i++)
		{
			isJolly &= (diffs[i] == (i + 1));
		}

		if (isJolly)
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;
	}

	return 0;
}
