#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;

#define FOR(i,n,m) for(int i=(n); i<(m); i++)
#define endl "\n"
#define ALPHA 26
struct TrieNode
{
	TrieNode *children[ALPHA];
	bool terminal;

	TrieNode()
		: terminal(false)
	{
		memset(children, 0, sizeof(children));
	}
	~TrieNode()
	{
		FOR(i, 0, ALPHA)
			if (children[i]) delete children[i];
	}
	
	void insert(const char* key)
	{
		if (*key == 0)
		{
			terminal = true;
			return;
		}
		else
		{
			int next = *key - 'a';

			if (children[next] == NULL)
				children[next] = new TrieNode();
			children[next]->insert(key + 1);
		}
	}

	bool find(const char* key, int& cnt)
	{
		if (*key == 0)
		{
			if (terminal == true)
				return true;
			else
				return false;
		}
		int next = *key - 'a';
		if (children[next] == NULL)
		{
			if (terminal == true)
				return true;
			else
				return false;
		}
		cnt = cnt + 1;
		return children[next]->find(key + 1, cnt);
	}
};

int N, M;
int answer = 0;
string t;
bool visited[300000];
TrieNode *L = new TrieNode();

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> t;
	
	cin >> M;
	string a;

	FOR(i, 0, M)
	{
		cin >> a;
		
		L->insert(a.c_str());
	}
}

void solve()
{
	int cnt = 0;
	FOR(i, 0, N)
	{
		bool isFind = L->find(t.substr(i).c_str(),cnt);
		if (isFind == true)
		{
			FOR(j, i, i + cnt)
				visited[j] = true;
		}
		cnt = 0;
	}
	FOR(i, 0, N)
		if (!visited[i])
		{
			//cout << i << " " << endl;
			answer++;
		}
	cout << answer << endl;
}

int main()
{
	input();
	solve();
	return 0;
}
/*

*/