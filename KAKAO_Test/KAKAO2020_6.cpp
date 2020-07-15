#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <bitset>
#include <cmath>
#include <unordered_map>
#include <queue>
#include <functional>
#include <cstring>
#include <limits>
using namespace std;

#define FOR(i,m,n) for(int i=(m); i<(n); i++)
int N;
int graph[201];
bool visited[201]; 
int ans=9;
vector<int> c_weak;
priority_queue<int> pq;
int limit;

void dfs(int begin, int count)
{
	//limit에 도달하면 return;
	
	count += 1;
	if (count == limit || pq.empty()) 
		return;

	int loop = pq.top();
	/*cout << loop << endl;*/
	pq.pop();
	int save_loop_count = 0;
	FOR(i, 0, loop + 1)
	{
		save_loop_count++;
		int loc = (begin + i) % N;
		if (graph[loc] == 1)
		{
			if (visited[loc] == false)
				visited[loc] = true;
			else
				break;
		}
	}
	// 모두 다 공사했으면 count min값 확인
	bool isFinish=true;
	FOR(i, 0, c_weak.size())
		if (visited[c_weak[i]] == false)
			isFinish = false;
	if (isFinish == true)
	{
		limit = count;
		ans = ans > count ? count : ans;
	}

	// 공사할 곳이 남았다면 다음 친구 넣기
	FOR(i, 0, c_weak.size())
	{
		if (visited[c_weak[i]] == false)
		{
			dfs(c_weak[i], count);
		}
	}
	
	//FOR(i, 0, N)
	//{
	//	cout << visited[i] << " ";
	//}
	//cout << endl;
	pq.push(loop);
	FOR(i, 0, save_loop_count)
	{
		int loc = (begin + i) % N;
		if (graph[loc] == 1)
			visited[loc] = false;
	}
}


int solution(int n, vector<int> weak, vector<int> dist) {
	int answer = 0;
	N = n;
	c_weak.reserve(weak.size());
	c_weak = weak;
	FOR(i, 0, dist.size())
		pq.push(dist[i]);

	FOR(i, 0, weak.size())
		graph[weak[i]] = 1;

	limit = dist.size();
	FOR(i, 0, weak.size())
		dfs(weak[i],  0);

	answer = ans;
	if (answer == 9)
		answer = -1;

	cout << answer << endl;
	return answer;
}

int main()
{
	int n = 200;
	vector<int> w({ 12,24,30, 54,70,82, 90, 102, 123, 154,170, 185 ,198});
	vector<int> d({ 25, 20, 26, 12,10,20, 7});

	solution(n, w, d);
	return 0;
}
/*
12
1, 3, 4, 9, 10
3, 5, 7

12
1,4,6,10
1,2,3,4

24
1,6, 7, 13, 17, 18, 19, 22, 23
5, 4, 3 ,2, 1

50
1, 5, 10, 12, 22, 25
4, 3, 2, 1
*/