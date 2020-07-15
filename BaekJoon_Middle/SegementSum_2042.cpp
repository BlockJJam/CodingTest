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

//±∏∞£¡D ∆Ê¿®∆Æ∏Æ
struct FenwickTree
{
	vector<ll> tree;
	FenwickTree(int n)
	{
		tree = vector<ll>(n + 1, 0);
	}
	// A[0..pos] ∫Œ∫–¡D
	ll sum(int pos)
	{
		//index∞° 1∫Œ≈Õ
		++pos;
		ll ret = 0;
		while (pos > 0)
		{
			ret += tree[pos];
			//cout << "S " << ret << " " << pos << endl;
			pos -= (pos&-pos);
			
		}
		return ret;
	}
	// A[pos]ø° val¿ª ¥ı«—¥Ÿ.
	void add(int pos, ll val)
	{
		++pos;
		while (pos < tree.size())
		{
			tree[pos] += val;
			//cout <<"A " << tree[pos] << " " << pos << endl;
			pos += (pos&-pos);
		}
	}
};

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	ll in;
	FenwickTree FTree{ N };
	FOR(i, 0, N)
	{
		cin >> in;
		FTree.add(i, in);
		vec.push_back(in);
	}

	
	FOR(i, 0, M + K)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			int index = b - 1;
			ll nValue = c;
			vec[index] = nValue - vec[index];
			FTree.add(index, vec[index]);
			vec[index] = nValue;
		}
		if (a == 2)
		{
			int left = b - 1;
			int right = c - 1;
			if (left > right)
				swap(left, right);
			ll answer = FTree.sum(right) - FTree.sum(left-1);
			cout << answer << endl;
		}
	}
}

int main()
{
	input();
	
	return 0;
}