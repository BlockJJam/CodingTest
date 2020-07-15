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
#define ll long long
int N;
string target;
string answer;
pair<ll, ll> point;

void gogo(ll y, ll x,ll py, ll px, int n)
{
	if (n == 0)
		return;

	//cout << answer << endl;
	ll fs = pow(2, n);
	if (py < y + (fs / 2) && px < x + (fs / 2))
	{
		answer += "2";
		gogo(y, x, py, px, n - 1);
	}
	else if (py < y + (fs / 2) && px >= x + (fs / 2))
	{
		answer += "1";
		gogo(y, x + (fs / 2), py, px, n - 1);
	}
	else if (py >= y + (fs / 2) && px < x + (fs / 2))
	{
		answer += "3";
		gogo(y + (fs / 2), x, py, px, n - 1);
	}
	else
	{
		answer += "4";
		gogo(y + (fs / 2), x + (fs / 2), py, px, n - 1);
	}
}

void go(ll y, ll x, int s, int n)
{
	ll fs = pow(2, n);
	if (s == target.size())
	{
		//cout << y << " " << x << endl;
		point.first = y;
		point.second = x;
		return;
	}

	if (target[s] == '2')
		go(y, x, s + 1, n - 1);
	else if (target[s] == '1')
		go(y, x + (fs / 2), s + 1, n - 1);
	else if (target[s] == '3')
		go(y + (fs / 2), x, s + 1, n - 1);
	else
		go(y + (fs / 2), x + (fs / 2), s + 1, n - 1);
}

void solve(pair<ll, ll> &target_point, bool isFindPoint)
{
	if (isFindPoint)
		go(0,0,0, N);
	else
		gogo(0, 0, target_point.first, target_point.second, N);
}

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> target;

	solve(point, true);
	
	ll x, y;
	cin >> x >> y;

	if (point.second + x >= 0 && point.second + x < pow(2, N) && point.first - y >= 0 && point.first - y < pow(2, N))
	{
		point.first = point.first - y;
		point.second = point.second + x;
		solve(point, false);
		cout << answer << endl;
	}
	else
	{
		cout << -1 << endl;
	}
}

int main()
{
	input();

	return 0;
}