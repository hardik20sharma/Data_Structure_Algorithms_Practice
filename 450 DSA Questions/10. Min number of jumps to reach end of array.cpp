#include <bits/stdc++.h>
using namespace std;

int minJumps(vector<int> &vec)
{
	vector<int> jumps(vec.size());

	if (vec.size() == 0 || vec[0] == 0)
		return INT_MAX;

	jumps[0] = 0;

	for (int i = 1; i < vec.size(); i++)
    {
		jumps[i] = INT_MAX;

        	for (int j = 0; j < i; j++)
				if (i <= (j + vec[j]) && jumps[j] != INT_MAX)
            	{
					jumps[i] = min(jumps[i], jumps[j] + 1);
					break;
				}
	}

	return jumps[vec.size() - 1];
}

int main()
{
	vector<int> vec { 1, 2, 3, 4, 5 };
	cout << "Minimum number of jumps to reach end is " << minJumps(vec);
}
