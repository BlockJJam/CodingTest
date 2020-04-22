#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

vector<int> S;
vector<int> seq;
int S_size, seq_size = 6;
int k;
vector<vector<int>> result;
queue<int> empty_line;

void solve(int n, int m)
{
	if (m == 0)
	{
		result.push_back(seq);


		return;
	}

	for (int i = 0; i < n; i++)
	{
		seq[seq_size - m] = S[i];
		if (seq_size - m > 0 && seq[seq_size - m - 1] > seq[seq_size - m])
			continue;
		S.erase(S.begin() + i);
		solve(n - 1, m - 1);
		S.insert(S.begin() + i, seq[seq_size - m]);
	}
}

void input()
{
	cin >> k;
	S.reserve(k);
	S_size = k;
	seq = vector<int>(6, 0);

	if (k == 0) return;

	for (int i = 0; i < k; i++)
	{
		int num;
		cin >> num;
		S.push_back(num);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		input();
		if (k == 0) break;

		solve(S_size, seq_size);

		//empty line Ã¤¿ì±â
		empty_line.push(result.size());

		seq.clear();
		S.clear();
	}
	for (int i = 0; i < result.size(); i++)
	{
		if (empty_line.front() == i)
		{
			cout << endl;
			empty_line.pop();
		}
		for (int j = 0; j < 6; j++)
			cout << result[i][j] << " ";
		cout << endl;

	}
	return 0;
}