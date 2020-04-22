#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
using namespace std;

int graph[101];
int hidden[101];
int min_count=1500;
int N, M;
queue<int> q;
// visited[] 에 들어있는 count가 nextCnt보다 크다면 들를 필요가 없다
int visited[101];

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a] = b;
		hidden[a] = 1; //ladder
	}
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a] = b;
		hidden[a] = 2; //snake
	}

	for (int i = 0; i < 101; i++)
		visited[i] = 1000000;
}


void solve()
{
	int q_size = 0;
	int count = 0;
	visited[1] = 0;

	while (!q.empty())
	{
		int q_size = q.size();
		while (q_size--)
		{
			int begin = q.front();
			q.pop();

			if (begin == 100)
			{
				min_count = min(count, min_count);
				cout << min_count << endl;
				//while (!q.empty()) q.pop();
				return;
			}

			for (int i = 1; i <= 6; i++)
			{
				if (begin + i > 100) 
					continue;
				
				if (hidden[begin + i] == 1 && visited[begin+i] > count +1 )
				{
					visited[begin + i] = count+1;
					q.push(graph[begin + i]);
				}
				else if (hidden[begin + i] == 2 && visited[begin+i] > count+ 1)
				{
					visited[begin + i] = count+1;
					q.push(graph[begin + i]);
				}
				else if(visited[begin+i] > count +1)
				{
					
					visited[begin + i] = count + 1;
					q.push(begin + i);
				}
			}
		}
		count++;
	}
}

int main()
{
	input();
	q.push(1);
	solve();

	return 0;
}