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
#include <sstream>
using namespace std;

#define FOR(i,m,n) for(int i=(m) ; i<(n); i++)
#define endl "\n"

int N;

void change(vector<int> &a, int now)
{
	FOR(i, now - 1, now + 2)
	{
		if (i >= 0 && i < a.size())
			a[i] = 1 - a[i];
	}
}

pair<bool, int> go(vector<int> bulb, vector<int> &result)
{
	int ans = 0;

	FOR(i, 0, bulb.size()-1)
	{
		if (bulb[i] != result[i])
		{
			//cout << i << " " << bulb[i] << " " << result[i] << endl;
			change(bulb, i + 1);
			ans++;
		}
	}

	if (bulb == result)
	{
		return { true , ans };
	}
	else
	{
		return { false, ans };
	}
}

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<int> bulb(N);
	vector<int> result(N);

	string str;
	cin >> str;
	FOR(i, 0, N)
		bulb[i] = str[i] - '0';

	cin >> str;
	FOR(i, 0, N)
		result[i] = str[i] - '0';

	//cout << "!!" << endl;
	auto status1 = go(bulb, result);
	change(bulb, 0);

	//cout << "??" << endl;
	auto status2 = go(bulb, result);

	if (status2.first) status2.second++;

	if (status1.first && status2.first)
		cout << min(status2.second, status1.second) << endl;
	else if (status1.first)
		cout << status1.second << endl;
	else if (status2.first)
		cout << status2.second << endl;
	else
		cout << -1 << endl;
}

int main()
{
	input();

	return 0;
}