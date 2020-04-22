#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int N;
vector<string> map;
vector<vector<bool>> visited;
vector<int> houseCount;
queue<tuple<int, int>> visit_list;
int houseTag = 0;

void countHouseInGroup(int x, int y)
{
	visited[x][y] = true;
	visit_list.push(make_pair(x, y));
	houseCount.push_back(1);
	while (!visit_list.empty())
	{
		auto t = visit_list.front();
		visit_list.pop();
		int x1 = get<0>(t), y1 = get<1>(t);

		if ((x1 - 1) >= 0 && map[x1 - 1][y1] == '1' && !(visited[x1-1][y1]))
		{
			visit_list.push(make_tuple(x1 - 1, y1));
			visited[x1 - 1][y1] = true;
			houseCount[houseTag] ++;
		}
		if ((x1 + 1) < N && map[x1 + 1][y1] == '1' && !(visited[x1 + 1][y1]))
		{
			visit_list.push(make_tuple(x1 + 1, y1));
			visited[x1 + 1][y1] = true;
			houseCount[houseTag] ++;
		}
		if ((y1 - 1) >= 0 && map[x1][y1-1] == '1' && !(visited[x1 ][y1 - 1]))
		{
			visit_list.push(make_tuple(x1, y1-1));
			visited[x1][y1-1] = true;
			houseCount[houseTag] ++;
		}
		if ((y1 + 1) <N && map[x1][y1+1] == '1' && !(visited[x1][y1+1]))
		{
			visit_list.push(make_tuple(x1, y1+1));
			visited[x1][y1+1] = true;
			houseCount[houseTag] ++;
		}
	}
	houseTag++;
}

void searchHouseGroup(int x)
{
	if (map.size() == 0) return;

	for(int i=0; i<N; ++i)
		for (int j = 0; j < N; ++j)
		{
			if (visited[i][j] == true || map[i][j] == '0')
			{
				visited[i][j] = true;
				continue;
			}
			countHouseInGroup(i, j);
		}
}

int main()
{
	cin >> N;
	map = vector<string>(N);
	for (int i = 0; i < N; ++i)
		cin >> map[i];

	visited = vector<vector<bool>>(N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			visited[i].push_back(false);

	searchHouseGroup(0);

	cout << houseTag << "\n";
	sort(houseCount.begin(), houseCount.end());
	for (int i = 0; i < houseCount.size(); i++)
		cout << houseCount[i] << "\n";

	return 0;
}

