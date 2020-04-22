#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int N;
int M;
vector<int> seq;
vector<int> answer;

// ��� ���� 15649
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

// �ߺ� ���� �������� ���� 15650
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

// ���� ���� ������ ��� �Ǵ� ����
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

// ���� ���� ������ ��� �ǰ� �񳻸����� ����
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

// ��� ������ ���ϵ� N�� ���Ұ� �־��� 15649
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

// N�� ���� �߿� �ߺ��Ǵ� ���� ����, �ߺ��Ǵ� ����� ���� �ʴ� ����

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