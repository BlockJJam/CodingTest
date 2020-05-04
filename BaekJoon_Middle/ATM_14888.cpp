#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <bitset>
#include <cmath>
using namespace std;

#define FOR(i,n) for(int i=0; i<(n); i++)
#define endl "\n"

int N, total_time = 0;
vector<int> N_vec, wait_time;

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		N_vec.push_back(a);
	}
}

void calc(int wait, int index)
{
	if (index == N)
		return;

	//cout << wait << endl;
	wait += N_vec[index];
	wait_time.push_back(wait);
	calc(wait, index+1);
}

void solve()
{
	sort(N_vec.begin(), N_vec.end());
	
	int wait = 0;
	int index = 0;
	calc(wait, index);

	for (auto& e : wait_time)
	{
		total_time += e;
	}
	cout << total_time << endl;

}

int main()
{
	input();
	solve();

	return 0;
}
