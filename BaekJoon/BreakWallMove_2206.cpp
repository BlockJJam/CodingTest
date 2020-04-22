#pragma warning (disable:4996)

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

int map[1001][1001];
int visited[1001][1001][2];
char tmp[1001];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n, m;

typedef struct st {
	int y;
	int x;
	int breakWall;
}st;

int bfs() {
	std::queue<st>q;
	q.push({ 0,0,0 });
	visited[0][0][0] = 1;

	int cnt = 0;

	while (!q.empty()) {
		int qSize = q.size();
		while (qSize--) {
			int y = q.front().y;
			int x = q.front().x;
			int breakWall = q.front().breakWall;
			q.pop();
			//std::cout << y << " " << x << std::endl;
			if (y == n - 1 && x == m - 1) return cnt + 1;

			for (int i = 0; i < 4; i++) {
				int yy = y + dy[i];
				int xx = x + dx[i];
				if (yy >= 0 && xx >= 0 && yy < n && xx < m && visited[yy][xx][breakWall] == 0) {
					if (map[yy][xx] == 0) {
						q.push({ yy, xx, breakWall });
						visited[yy][xx][breakWall] = 1;
					}
					else if (breakWall == 0) {
						q.push({ yy, xx, 1 });
						visited[yy][xx][1] = 1;
					}
				}
			}
		}
		cnt++;
	}
	return -1;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", &tmp);
		for (int j = 0; j < m; j++) {
			map[i][j] = tmp[j] - '0';
		}
	}
	printf("%d", bfs());
}