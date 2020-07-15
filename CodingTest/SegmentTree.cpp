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

int N, M, K;
vector<ll> vec;

// 구간트리를 이용한 구간별 최소값
struct RMQ
{
	int n;
	vector<ll> rangeMin;

	RMQ(vector<ll>& vec)
	{
		n = vec.size();
		rangeMin.resize(n * 4);
		init(vec, 0, n - 1, 1);
	}

	ll init(vector<ll>& vec, int left, int right, int node)
	{
		cout << left << " " << right << " " << node << endl;
		if (left == right)
			return rangeMin[node] = vec[left];

		int mid = (left + right) / 2;
		int leftMin = init(vec, left, mid, node * 2);
		int rightMin = init(vec, mid + 1, right, node * 2 + 1);

		return rangeMin[node] = min(leftMin, rightMin);
	}

	ll query(int left, int right, int node, int nodeL, int nodeR)
	{
		// 전체 노드와 안겹침
		if (right < nodeL || nodeR < left) return INT_MAX;

		// 완전 포함
		if (left <= nodeL && nodeR <= right)
			return rangeMin[node];

		// 양쪽 구간을 나눠서 합친다
		int mid = (nodeL + nodeR) / 2;
		return min(query(left, right, node * 2, nodeL, mid), query(left, right, node * 2 + 1, mid + 1, nodeR));
	}
	ll query(int left, int right)
	{
		return query(left, right, 1, 0, n - 1);
	}

	ll update(int index, ll newValue, int node, int nodeL, int nodeR)
	{
		if (index < nodeL || nodeR < index) return rangeMin[node];

		if (nodeL == nodeR)
			return rangeMin[node] = newValue;

		int mid = (nodeL + nodeR) / 2;

		return rangeMin[node] = min(update(index, newValue, node * 2, nodeL, mid), update(index, newValue, node * 2 + 1, mid + 1, nodeR));
	}

	ll update(int index, ll newValue)
	{
		return update(index, newValue, 1, 0, n - 1);
	}

};