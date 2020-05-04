#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <bitset>
using namespace std;

int N, K;
int coin_count=0;
vector<int> N_vec;

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int coin;
		cin >> coin;
		N_vec.push_back(coin);
	}
}

void solve(int k_copy, int coin_index)
{
	if (k_copy == 0)
	{
		cout << coin_count << endl;
		return;
	}

	if (k_copy > 0)
	{
		while (k_copy - N_vec[coin_index] < 0)
		{
			if (coin_index < 0) return;
			coin_index--;
		}
		while (true)
		{
			if (k_copy - N_vec[coin_index] < 0) break;

			k_copy -= N_vec[coin_index];
			coin_count++;
		}
		//cout << k_copy  << endl;
		solve(k_copy , coin_index-1);
	}
}

int main()
{
	input();
	solve(K, N - 1);
}