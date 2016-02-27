/*
UVa problem # 10107 - What is the Median?
URL: https://uva.onlinejudge.org/external/101/10107.pdf
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<long long> numbers;
	long long number;
	while (scanf("%lld \n", &number) != EOF)
	{
		numbers.push_back(number);
		std::sort(numbers.begin(), numbers.end());
		if (numbers.size() % 2 == 0)
		{
			cout << ((numbers[numbers.size()/2] + numbers[numbers.size()/2 -1])/2) << endl;
		}
		else
		{
			cout << (numbers[numbers.size() / 2]) << endl;
		}		
	}

	return 0;
}