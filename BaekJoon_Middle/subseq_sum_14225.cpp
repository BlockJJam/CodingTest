#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <bitset>
using namespace std;

bitset<20*100000> bit_sum;
int N;
vector<int> S;
set<int> sum_set;
vector<int> seq;
int seq_size = 0;
void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		S.push_back(num);
		//sum_set.insert(num);
	}
}

void solve(int begin, int sum)
{
	if (begin == N)
	{
		bit_sum.set(sum);
		return;
	}
	solve(begin + 1, sum + S[begin]);
	solve(begin + 1, sum);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve(0, 0);

	int check = 0;
	while (1)
	{
		if (bit_sum.test(check) != 1)
		{
			cout << check << "\n";
			return 0;
		}
		check++;
	}

	return 0;
}