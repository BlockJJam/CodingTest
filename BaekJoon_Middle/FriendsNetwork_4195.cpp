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
#define FOR(i,m,n) for(int i=(m); i<(n); i++)
#define endl "\n"

int T, F;
unordered_map<string, int> f_map;

struct DisjointSet
{
	vector<int> cnt;
	vector<int> rank;
	vector<int> parent;

	DisjointSet(int n)
		: parent(n), rank(n), cnt(n)
	{
		FOR(i, 0, n)
		{
			parent[i] = i;
			cnt[i] =1;
		}
	}

	int find(int u)
	{
		if (u == parent[u]) return u;

		return parent[u] = find(parent[u]);
	}

	int getCount(int u) 
	{
		return cnt[u];
	}

	void merge(int u, int v)
	{
		u = find(u);
		v = find(v);

		if (u == v)
		{
			cout << getCount(v) << endl;
			return;
		}
		if (rank[u] > rank[v]) 
			swap(u, v);
		
		cnt[v] += cnt[u];
		cout << getCount(v) << endl;
		parent[u] = v;

		if (rank[u] == rank[v])  
			++rank[v];
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--)
	{
		cin >> F;

		DisjointSet ds(F*2);
		int name_id = 0;

		FOR(i, 0, F)
		{
			string a, b;
			cin >> a >> b;
			if (f_map.end() == f_map.find(a))
			{
				f_map[a] = name_id;
				++name_id;
			}
			if (f_map.end() == f_map.find(b))
			{
				f_map[b] = name_id;
				++name_id;
			}
			ds.merge(f_map[a], f_map[b]);
		}
	}
}
