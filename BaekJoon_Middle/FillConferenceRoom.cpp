#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <bitset>
#include <cmath>
using namespace std;

#define ll long long

int N;
vector<pair<ll, ll>> conference;
ll first_time = 0; 
ll last_time ;
int total_confer = 0;
bool finished = false;

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		conference.push_back({ a,b });
	}

}

bool compareEnd(pair<ll,ll>& A,  pair<ll,ll>B)
{
	if (A.second != B.second)
	{
		if (A.second < B.second)
			return true;
		else
			return false;
	}
	else
	{
		if (A.first < B.first)
			return true;
		else
			return false;
	}
}

void fillConfer(int confer_index,ll start_time, ll end_time, int confer_count)
{
	if (confer_index == N)
	{
		total_confer = confer_count;
		return;
	}
	
	if (conference[confer_index].second > last_time)
	{
		total_confer = confer_count;
		return;
	}

	if (conference[confer_index].second >= end_time && conference[confer_index].first >= end_time)
	{
		//cout << conference[confer_index].first << " "<<  conference[confer_index].second << endl;
		fillConfer(confer_index + 1, conference[confer_index].first, conference[confer_index].second, confer_count + 1);
	}
	else
		fillConfer(confer_index + 1, start_time, end_time, confer_count);

}

void solve()
{
	// sort conference
	sort(conference.begin(), conference.end(), compareEnd);
	/*for (int i = 0; i < conference.size(); i++)
		cout << conference[i].first << " " << conference[i].second << endl;
	cout << endl;
	cout << last_time << endl;*/

	fillConfer(1, conference[0].first, conference[0].second, 1);
	cout << total_confer << endl;
}

int main()
{
	input();
	ll a = pow(2, 31) - 1;
	last_time = a;
	solve();

	return 0;
}