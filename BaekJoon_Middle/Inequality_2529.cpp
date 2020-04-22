#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int K;
vector<int> N;

string op;
vector<string> result;
//<int> sample;
vector<int> seq;
int seq_len;


void solve(int n, int m)
{
	if (m == 0)
	{
		string sample ="";
		for (int i = 0; i < seq_len; i++)
		{
			sample += to_string(seq[i]);
		}
		result.push_back(sample);

		return;
	}

	for (int i = 0; i < n; i++)
	{
		seq[seq_len - m] = N[i];
		if (seq_len - m > 0)
		{
			if (op[seq_len - m - 1] == '<' && seq[seq_len - m - 1] > seq[seq_len - m])
				continue;
			
			if (op[seq_len - m - 1] == '>' && seq[seq_len - m - 1] < seq[seq_len - m])
				continue;
		}

		N.erase(N.begin() + i);
		solve(n - 1, m - 1);
		N.insert(N.begin() + i, seq[seq_len - m]);
	}
}

void input()
{
	cin >> K;
	char c;
	for (int i = 0; i < K; i++)
	{
		cin >> c;
		op.push_back(c);
	}
	for (int i = 0; i < 10; i++)
		N.push_back(i);

	seq_len = K + 1;
	seq = vector<int>(seq_len, 0);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//모든 정보 입력
	input();

	solve(10, seq_len);
	
	sort(result.begin(), result.end());

	string min_val = result[0];
	string max_val = result[result.size() - 1];
	
	cout << max_val << endl;
	cout << min_val << endl;
}