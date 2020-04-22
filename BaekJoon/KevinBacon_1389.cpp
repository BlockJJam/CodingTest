#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int shortest;
int shortestIndex;
int graph[101][101];
vector<int> totalDist(101,0);

void floyd()
{
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (i == j) 
					graph[i][j] = 0;
				else 
					graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);

}

void totalShortestDist()
{
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (graph[i][j] < 101)
				totalDist[i] += graph[i][j];

	/*for (int j = 1; j <= N; j++)
		cout << totalDist[j] << " ";
	cout << endl;*/

	shortest = totalDist[1];
	for (int i = 1; i <= N; i++)
		if (shortest > totalDist[i])
			shortest = totalDist[i];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= N; j++)
			graph[i][j]=101;

	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		graph[A][B] = 1;
		graph[B][A] = 1;
	}
	/*for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cout << graph[i][j] << " ";
		cout << endl;
	}*/
	floyd();

	totalShortestDist();

	for (int i = 1; i <= N; i++)
		if (shortest == totalDist[i])
		{
			shortestIndex = i;
			break;
		}
	
	cout << shortestIndex;
}