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
#define endl "\n"

int N, M;
int card_count[500001];
unordered_map<int, int> same_card_map;
vector<long long> N_vec, M_vec;

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	FOR(i, N)
	{
		int a;
		cin >> a;
		N_vec.push_back(a);
		if (same_card_map.end() == same_card_map.find(a))
			same_card_map[a] = 1;
		else
			same_card_map[a]++;
	}
	cin >> M;
	FOR(i, M)
	{
		int a;
		cin >> a;
		M_vec.push_back(a);
	}
}

void searchM(int start, int end, long long number, int index)
{
	int mid = (start + end) / 2;
	if (start > end) return;
	if (number == N_vec[mid])
	{
		card_count[index] = same_card_map[number];
		return;
	}
	else if (N_vec[mid] > number)
	{
		searchM(start, mid - 1, number, index);
	}
	else
	{
		searchM(mid + 1, end, number, index);
	}
}

void solve()
{
	sort(N_vec.begin(), N_vec.end());

	FOR(i, M)
	{
		searchM(0, N - 1, M_vec[i], i);
	}

	FOR(i, M)
		cout << card_count[i] << " ";
	cout << endl;
}

int main()
{
	input();
	solve();

	return 0;
}