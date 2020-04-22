#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
using namespace std;

#define endl "\n"

int N;
struct Point
{
	int x, y;
};
vector<Point> point_vec;

void input()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		point_vec.push_back({ x,y });
	}
}

bool comparePoint(Point& A, Point& B)
{
	if (A.x != B.x)
	{
		if (A.x < B.x) return true;
		else return false;
	}
	else
	{
		if (A.y < B.y) return true;
		else return false;
	}
}

void solve()
{
	sort(point_vec.begin(), point_vec.end(), comparePoint);
}

void print()
{
	for (int i = 0; i < N; i++)
	{
		cout << point_vec[i].x << " " << point_vec[i].y << endl;
	}
}

int main()
{
	input();
	solve();
	print();
}