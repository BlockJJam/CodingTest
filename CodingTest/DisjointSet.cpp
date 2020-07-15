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
#define ll long long


template<class T>
struct NaiveDisjointSet
{
	vector<T> parent;
	NaiveDisjointSet(T n)
		: parent(n)
	{
		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}

	// u가 속한 트리의 root를 반환
	int find(T u) const
	{
		if (u == parent[u])
			return u;
		return find(parent[u]);
	}

	// u가 속한 트리와 v가 속한 트리를 합친다
	void merge(T u, T v)
	{
		u = find(u); v = find(v);
		//u와 v가 같은 root에 속하는 경우
		if (u == v) return;
		parent[u] = v;
	}
};

template<class T>
struct OptimizedDisjointSet
{
	vector<T> parent, rank;
	OptimizedDisjointSet(T n)
		: parent(n), rank(n)
	{
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int u)
	{
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);			// u가 속하는 트리의 루트를 찾았으면 그걸 parent[u]에 바로 넣어서 경로 압축 최적화 시킨다
	}

	void merge(int u, int v)
	{
		u = find(u); v = find(v);
		if (u == v) return;
		if (rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if (rank[u] == rank[v]) ++rank[v];
	}
};