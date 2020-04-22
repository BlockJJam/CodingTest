#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
using namespace std;

#define endl "\n"

int N, M;
vector<int> card, num;
vector<short> haveCard;

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a = 0;
		cin >> a;
		card.push_back(a);
	}
	 
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int b = 0;
		cin >> b;
		num.push_back(b);
	}
	sort(card.begin(), card.end());
}

void bin_search(int start, int end, int key)
{
	if (start > end)
	{
		haveCard.push_back(0);
		return;
	}
	
	int mid = (start + end ) / 2;
	if (card[mid] == key)
	{
		haveCard.push_back(1);
		return;
	}
	else if (card[mid] > key)
	{
		return bin_search(start, mid - 1, key);
	}
	else
	{
		return bin_search(mid + 1, end, key);
	}
}

void solve()
{
	for (int i = 0; i < M; i++)
	{
		bin_search(0, N - 1, num[i]);
	}
}

void print()
{
	for (int i = 0; i < haveCard.size(); i++)
	{
		cout << haveCard[i] << " ";
	}
}

int main()
{
	input();
	solve();
	print();

	return 0;

}