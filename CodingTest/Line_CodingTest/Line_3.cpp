#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>

using namespace std;
string s;
vector<int> num_loc;
vector<int> seq;
priority_queue<int> pq;

int N;

void solve(int n, int m)
{
	if (m == 0)
	{
		string s_copy = s;
		for (int i = 0; i < seq.size(); i++)
		{
			int pos = seq[i];
			s_copy[pos] = '1';
		}
		//���� ���ϱ�
		int length = 0;
		for (int i = 0; i < s_copy.size(); i++)
		{
			if (s_copy[i] == '1')
			{
				length++;
			}
			else
			{
				pq.push(length);
				length = 0;
			}
		}
		cout << pq.top();
		return;
	}


	for (int i = 0; i < n; i++)
	{
		
		seq[N - m] = num_loc[i];
		if (N - m > 0 && seq[N - m - 1] > seq[N - m])
			continue;
		num_loc.erase(num_loc.begin() + i);
		solve(n - 1, m - 1);
		num_loc.insert(num_loc.begin() + i, seq[N - m]);
	}
}

int solution(string road, int n) {
	int answer = -1;
	s = road;

	for (int i = 0; i < road.size(); i++)
		if (road[i] == '0')
			num_loc.push_back(i);

	// 0�� ������ n���� ������ return road.size()
	if (num_loc.size() < n) return road.size();
	seq = vector<int>(n,0);
	N = n;

	solve(num_loc.size(), n);
	answer = pq.top();
	cout << answer;
	return answer;
}



int main()
{
	string road = "111011110011111011111100011111";
	int n = 3;

	solution(road, n);

	return 0;
}