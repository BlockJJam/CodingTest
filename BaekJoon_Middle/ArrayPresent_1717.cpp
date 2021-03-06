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


vector<int> p;
int N, M;

#define FOR(i,n) for(int i=0; i<(n); i++)
#define endl "\n"
#define ll unsigned long long
const int MAX = 1000000;

int find(int x)
{
	if (x == p[x]) return x;
	else
		return p[x] = find(p[x]);
}

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	N = N + 1;
	FOR(i, N) p.push_back(i);

	FOR(i, M)
	{
		int op, a, b;
		cin >> op >> a >> b;

		if (op == 0)
		{
			a = find(a);
			b = find(b);

			if (a > b) p[a] = b;
			else p[b] = a;
		}
		if(op == 1)
		{
			a = find(a);
			b = find(b);
			if (a == b) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}

int main()
{
	input();
	return 0;
}