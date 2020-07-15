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

	// u�� ���� Ʈ���� root�� ��ȯ
	int find(T u) const
	{
		if (u == parent[u])
			return u;
		return find(parent[u]);
	}

	// u�� ���� Ʈ���� v�� ���� Ʈ���� ��ģ��
	void merge(T u, T v)
	{
		u = find(u); v = find(v);
		//u�� v�� ���� root�� ���ϴ� ���
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
		return parent[u] = find(parent[u]);			// u�� ���ϴ� Ʈ���� ��Ʈ�� ã������ �װ� parent[u]�� �ٷ� �־ ��� ���� ����ȭ ��Ų��
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