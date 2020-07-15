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
#include <limits>
using namespace std;

#define FOR(i,n,m) for(int i=(n); i<(m); i++)
#define endl "\n"


int N, M;
vector<int> vec;
vector<pair<int, int>> answer;
queue < pair < int, int>> q;
#define INT_MAX 2147483647 

struct RMQ
{
	int n;
	vector<int> rangeMin;
	vector<int> rangeMax;

	RMQ(vector<int>& vec)
	{
		n = vec.size();
		rangeMin.resize(n * 4);
		rangeMax.resize(n * 4);
		init_min(vec, 0, n - 1, 1);
		init_max(vec, 0, n - 1, 1);
	}

	int init_min(vector<int>& vec, int left, int right, int node)
	{
		//cout << left << " " << right << " " << node << endl;
		if (left == right)
		{
			//cout << node <<" "<< vec[left] << " min" << endl;
			return rangeMin[node] = vec[left];
		}
		int mid = (left + right) / 2;
		int leftMin = init_min(vec, left, mid, node * 2);
		int rightMin = init_min(vec, mid + 1, right, node * 2 + 1);

		return rangeMin[node] = min(leftMin, rightMin);
	}

	int init_max(vector<int>& vec, int left, int right, int node)
	{
		//cout << left << " " << right << " " << node << endl;
		if (left == right)
		{
			//cout << node << " " << vec[left] << " max" << endl;
			return rangeMax[node] = vec[left];
		}
		int mid = (left + right) / 2;
		int leftMax = init_max(vec, left, mid, node * 2);
		int rightMax = init_max(vec, mid + 1, right, node * 2 + 1);

		return rangeMax[node] = max(leftMax, rightMax);
	}

	int query_min(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		if (right < nodeLeft || nodeRight < left) return INT_MAX;

		if (left <= nodeLeft && nodeRight <= right)
			return rangeMin[node];

		int mid = (nodeLeft + nodeRight) / 2;
		return min(
			query_min(left, right, node * 2, nodeLeft, mid),
			query_min(left, right, node * 2 + 1 , mid + 1, nodeRight)
		);
	}

	int query_max(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		if (right < nodeLeft || nodeRight < left) return -1;

		if (left <= nodeLeft && nodeRight <= right)
			return rangeMax[node];

		int mid = (nodeLeft + nodeRight) / 2;
		return max(
			query_max(left, right, node * 2, nodeLeft, mid),
			query_max(left, right, node * 2 + 1 , mid + 1, nodeRight)
		);
	}

	int query(int left, int right, int check)
	{
		if (check == 0)
			return query_min(left, right, 1, 0, n - 1);
		else
			return query_max(left, right, 1, 0, n - 1);
	}
};

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	FOR(i, 0, N)
	{
		int a;
		cin >> a;
		vec.push_back(a);
	}
	FOR(i, 0, M)
	{
		int a, b;
		cin >> a >> b;

		q.push({ a-1,b-1 });
	}
}

void solve()
{
	RMQ rmq(vec);

	while (!q.empty())
	{
		int left = q.front().first;
		int right = q.front().second;
		q.pop();

		int min = rmq.query(left, right, 0);
		int max = rmq.query(left, right, 1);
		cout << min << " " << max << endl;
	}
}

int main()
{
	input();
	solve();

	return 0;
}