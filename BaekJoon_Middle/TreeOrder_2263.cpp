// 분할정복, 이진트리 순회

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <bitset>
#include <cmath>
#include <unordered_map>
using namespace std;

#define FOR(i,n) for(int i=0; i<(n); i++)

const int MAX = 100001;

int N;
int post[MAX], in[MAX];
int idx[MAX];

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	FOR(i, N)
	{
		cin >> in[i];
	}
	FOR(i, N)
	{
		cin >> post[i];
	}
}

void preOrder(int inBegin, int inEnd, int postBegin, int postEnd)
{
	// 기저
	if (inBegin > inEnd || postBegin > postEnd)
	{
		return;
	}

	int pre_root = post[postEnd];
	cout << pre_root << " ";
	
	// 왼쪽 서브트리
	preOrder(inBegin, idx[pre_root] - 1, postBegin, postBegin + (idx[pre_root] - inBegin) - 1);

	// 오른쪽 서브트리
	preOrder(idx[pre_root] + 1, inEnd, postBegin + (idx[pre_root] - inBegin), postEnd - 1);
}

void solve()
{
	FOR(i, N)
	{
		idx[in[i]] = i;
	}

	preOrder(0, N - 1, 0, N - 1);
}

int main()
{
	input();
	solve();
}