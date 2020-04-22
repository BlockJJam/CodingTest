#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int N;
int M;
vector<int> seq;
vector<int> answer;

// 모든 수열 15649
void sequence15649(int n, int m)
{
	if (m == 0)
	{
		for (int i = 0; i < M; i++)
			cout << answer[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++)
	{
		answer[M-m] = seq[i];
		seq.erase(seq.begin() + i);
		sequence15649(n - 1, m - 1);
		seq.insert(seq.begin() + i, answer[M - m]);
	}
}

// 중복 없는 오름차순 순열 15650
void sequence15650(int n, int m)
{
	if (m == 0)
	{
		for (int i = 0; i < M; i++)
			cout << answer[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++)
	{
		answer[M - m] = seq[i];
		if ((M - m) > 0 && (answer[M - m - 1] > answer[M - m]))
			continue;
		seq.erase(seq.begin() + i);
		sequence15650(n - 1, m - 1);
		seq.insert(seq.begin() + i, answer[M - m]);
	}
}

// 같은 수를 여러번 골라도 되는 수열
void sequence15651(int n, int m)
{
	if (m == 0)
	{
		for (int i = 0; i < M; i++)
			cout << answer[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		answer[M - m] = seq[i];
		sequence15651(n - 1, m - 1);
	}
}

// 같은 수를 여러번 골라도 되고 비내림차순 수열
void sequence15652(int n, int m)
{
	if (m == 0)
	{
		for (int i = 0; i < M; i++)
			cout << answer[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		answer[M - m] = seq[i];
		if ((M - m) > 0 && (answer[M - m - 1] > answer[M - m]))
			continue;
		sequence15652(n - 1, m - 1);
	}
}

// 모든 수열을 구하되 N의 원소가 주어짐 15649
void sequence15653(int n, int m)
{
	if (m == 0)
	{
		for (int i = 0; i < M; i++)
			cout << answer[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++)
	{
		answer[M - m] = seq[i];
		seq.erase(seq.begin() + i);
		sequence15653(n - 1, m - 1);
		seq.insert(seq.begin() + i, answer[M - m]);
	}
}

// N의 원소 중에 중복되는 수가 있음, 중복되는 결과는 담지 않는 수열

void sequence15663(int n, int m)
{
	if (m == 0)
	{
		for (int i = 0; i < M; i++)
			cout << answer[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++)
	{
		answer[M - m] = seq[i];
		if (i>0 && seq[i - 1] == seq[i])
			continue;
		seq.erase(seq.begin() + i);
		sequence15663(n - 1, m - 1);
		seq.insert(seq.begin() + i, answer[M - m]);
	}
}

int main()
{
	cin >> N >> M;
	seq = vector<int>(N, 0);

	//for (int i = 0; i < N; i++)
	//	seq[i] = i + 1;

	for (int i = 0; i < N; i++)
		cin >> seq[i];
	sort(seq.begin(),seq.end());

	answer = vector<int>(M, 0);
	sequence15650(N, M);


	return 0;
}