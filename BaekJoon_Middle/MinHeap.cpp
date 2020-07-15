#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <bitset>
#include <cmath>
#include <unordered_map>
#include <queue>
#include <functional>
#include <cstring>
using namespace std;

#define FOR(i,n) for(int i=0; i<(n); i++)
#define endl "\n"
#define ll unsigned long long
const int MAX = 100001;

int N;
priority_queue<int, std::vector<int>, std::greater<int>> pq;

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	FOR(i, N)
	{
		int x;
		cin >> x;
		if (x == 0)
		{
			if (pq.empty())
				cout << 0 << endl;
			else
			{
				cout << pq.top() << endl;
				pq.pop();
			}
		}
		else
			pq.push(x);
	}
}

int main()
{
	input();

	return 0;
}