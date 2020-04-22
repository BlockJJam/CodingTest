#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_S 1000000000
#define MIN_S -1000000000
#define endl "\n"

int T, N, M;
int max_result = MIN_S;
int min_result = MAX_S;

vector<int> num_arr, seq, oper_arr;
// 0: + ,1: -, 2: *, 3:/
vector<int> result;

int add_me(int a, int b)
{
	return a + b;
}
int sub_me(int a, int b)
{
	return a - b;
}
int mul_me(int a, int b)
{
	return a * b;
}
int div_me(int a, int b)
{
	return a / b;
}

void solve(int n, int m)
{
	if (m == 0)
	{
		/*for (int i = 0; i < M; i++)
			cout << oper_arr[i] << " ";
		cout << endl;*/
		int oper_result = num_arr[0];
		for (int i = 0; i < oper_arr.size(); i++)
		{
			if (oper_arr[i] == 0)
				oper_result = add_me(oper_result, num_arr[i + 1]);
			else if (oper_arr[i] == 1)
				oper_result = sub_me(oper_result, num_arr[i + 1]);
			else if (oper_arr[i] == 2)
				oper_result = mul_me(oper_result, num_arr[i + 1]);
			else
				oper_result = div_me(oper_result, num_arr[i + 1]);
		}
		max_result = max(max_result, oper_result);
		min_result = min(min_result, oper_result);
		//cout << max_result << "," << min_result << endl;;

		return;
	}

	for (int i = 0; i < n; i++)
	{
		oper_arr[M - m] = seq[i];
		if (i > 0 && seq[i - 1] == seq[i])
			continue;
		seq.erase(seq.begin() + i);
		solve(n - 1, m - 1);
		seq.insert(seq.begin() + i, oper_arr[M - m]);
	}
}



void input()
{
	cin >> N;
	M = N - 1;
	oper_arr = vector<int>(M, 0);

	for (int i = 0; i < 4; i++)
	{
		int x;
		cin >> x;
		for (int j = 0; j < x; j++)
			seq.push_back(i);
	}

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		num_arr.push_back(x);
	}
}

void clear()
{
	num_arr.clear();
	oper_arr.clear();
	seq.clear();
	max_result = MIN_S;
	min_result = MAX_S;
}

int main()
{
	FILE *f;
	freopen_s(&f, "sample_input.txt", "r", stdin);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		input();
		solve(M, M);

		int total = max_result - min_result;
		result.push_back(total);

		clear();
	}
	for (int i = 0; i < T; i++)
		cout << "#" << i+1 << " " << result[i]<<endl;

	return 0;
}