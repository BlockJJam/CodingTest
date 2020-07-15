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
using namespace std;

#define FOR(i,m,n) for(int i=(m); i<(n); i++)
#define endl "\n"

int N;
int r, c;
int cnt = 0;
void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> r >> c;
}

void recursion(int row, int col, int range)
{
	//cout << row << " . " << col <<" , " << range << endl;
	if (row == r && col == c)
	{
		cout << cnt;
		return;
	}

	if (r < row + range && r >= row && c < col + range && c >= col)
	{
		recursion(row, col, range / 2);
		recursion(row, col + range/2, range / 2);
		recursion(row + range/2, col, range / 2);
		recursion(row + range/2, col + range/2, range / 2);
	}
	else
	{
		cnt += range * range;
	}
}

int main()
{
	input();
	recursion(0,0,pow(2,N));

}