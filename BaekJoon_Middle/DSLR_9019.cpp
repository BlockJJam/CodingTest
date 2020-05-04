/*
	���� �� �ִ� ��� ���� ���� ( 0 ~ 10000 ) �湮 ó���� �ʼ�
	��, DSL 1000 �� ���Դµ� LLDD�� 1000�� ���Դٸ� �� ���� ������ �� �ʿ䰡 ������???
		-> ����

*/

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

#define FOR(i,n) for(int i=0; i<(n); i++)
const int MAX = 10001;

int a, b;
bool visit[10001];
void recv(int num) {
	visit[num] = 1;
	queue<pair<int, string> > q;
	q.push({ num,"" });
	while (!q.empty()) {
		int num = q.front().first;
		string change = q.front().second;	q.pop();
		if (num == b) {
			cout << change << "\n";
			return;
		}

		int curNum = (2 * num) % 10000;
		if (!visit[curNum]) {
			visit[curNum] = true;
			q.push(make_pair(curNum, change + "D"));
		}

		curNum = (num ? num - 1 : 9999);
		if (!visit[curNum]) {
			visit[curNum] = true;
			q.push(make_pair(curNum, change + "S"));
		}

		curNum = (num % 1000) * 10 + num / 1000;
		if (!visit[curNum]) {
			visit[curNum] = true;
			q.push(make_pair(curNum, change + "L"));
		}

		curNum = (num % 10) * 1000 + (num / 10);
		if (!visit[curNum]) {
			visit[curNum] = true;
			q.push(make_pair(curNum, change + "R"));
		}
	}
}
void solve() {
	cin >> a >> b;
	recv(a);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	for (; t--;) {
		memset(visit, 0, sizeof(visit));
		solve();
	}
}