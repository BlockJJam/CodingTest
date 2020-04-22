#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

#define MAX_S 17
#define endl "\n"

int T, N,M;
int graph[MAX_S][MAX_S];
bool visited[MAX_S];
vector<int> A,B,seq,diff;
vector<int> test_result;

void solve(int n, int m)
{
	if (m == 0)
	{
		int A_favor = 0, B_favor = 0;
		//A와 B의 맛의 차이 구하기
		for (int i = 0; i < M; i++)
			visited[A[i]] = true;

		for (int i = 0; i < N; i++)
			if (visited[i] == false)
				B.push_back(i);

		// A,B 재료번호가 채워짐 -> A의 맛과 B의 맛을 구해
		for(int i=0; i<M; i++)
			for (int j = i + 1; j < M; j++)
			{
				int favor = graph[A[i]][A[j]] + graph[A[j]][A[i]];
				A_favor += favor;
			}
		for (int i = 0; i < M; i++)
			for (int j = i + 1; j < M; j++)
			{
				int favor = graph[B[i]][B[j]] + graph[B[j]][B[i]];
				B_favor += favor;
			}
		// 만든 A,B 음식에 차이를 diff에 넣어
		diff.push_back(abs(A_favor - B_favor));

		B.clear();
		memset(visited, false, sizeof(visited));

		return;
	}

	for (int i = 0; i < n; i++)
	{
		A[M - m] = seq[i];
		if (M - m > 0 && A[M - m - 1] > A[M - m])
			continue;
		seq.erase(seq.begin() + i);
		solve(n - 1, m - 1);
		seq.insert(seq.begin() + i, A[M - m]);
	}
}

int main()
{
	/*FILE *f;
	freopen_s(&f, "sample_input.txt", "r", stdin);*/

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		M = N / 2;

		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				cin >>graph[j][k];

		for (int i = 0; i < N; i++)
			seq.push_back(i);

		A = vector<int>(M, 0);
		solve(N,M);

		//diff 중에 가장 작은 값을 test_result에 넣어
		sort(diff.begin(), diff.end());
		test_result.push_back(diff[0]);

		fill(&graph[0][0], &graph[MAX_S-1][MAX_S], 0);
		seq.clear();
		diff.clear();
	}

	for (int i = 0; i < T; i++)
		cout << "#" << i+1 << " " << test_result[i] << endl;

	return 0;
}
