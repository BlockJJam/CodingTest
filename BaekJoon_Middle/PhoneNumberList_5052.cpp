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
#define ll long long

const int NUM = 10;
int toNumber(const char ch) { return ch - '0'; }

int T, N;
bool answer = true;

struct TrieNode
{
	TrieNode* children[NUM];
	bool terminal;

	TrieNode()
		: terminal(false)
	{
		fill(children, children + NUM, nullptr);
	}
	~TrieNode()
	{
		FOR(i, 0, NUM)
		{
			if (children[i])
				delete children[i];
		}
	}

	//문자열 추가
	void insert(const char* key)
	{
		//cout << key << endl;
		if (*key == '\0')
		{
			terminal = true;
		}
		else
		{
			int next = toNumber(*key);
			if (children[next] == NULL)
				children[next] = new TrieNode();

			children[next]->insert(key + 1);
		}
	}
	bool find(const char* key)
	{
		if (*key == '\0') return false;
		if (terminal) return true;

		int next = toNumber(*key);
		return children[next]->find(key + 1);
	}
};

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	

	while (T--)
	{
		//cout << T << endl;
		TrieNode* trie = new TrieNode();
		char phone[10001][11];
		cin >> N;
		FOR(i, 0, N)
		{
			cin >> phone[i];

			trie->insert(phone[i]);
		}
		FOR(i, 0, N)
		{
			if (trie->find(phone[i]))
			{
				answer = false;
				break;
			}
		}
		if (answer == false)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;

		answer = true;
		delete trie;
	}
}

int main()
{
	input();

	return 0;
}