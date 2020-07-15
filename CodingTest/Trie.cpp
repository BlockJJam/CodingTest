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

const int ALPHA = 26;
int toNumber(char ch) { return ch - 'A'; }

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
		for (int i = 0; i < ALPHA; ++i)
			if (children[i]) delete children[i];
	}

	//트라이에 문자열 추가
	void insert(const char* key)
	{
		if (*key == 0)
			terminal = true;
		else
		{
			int next = toNumber(*key);

			if (children[next] == NULL)
				children[next] = new TrieNode();
			children[next]->insert(key + 1);
		}
	}

	//이 노드를 루트로 하는 트라이에 문자열 key와 대응되는 노드를 찾는다
	//없으면 NULL반환
	TrieNode* find(const char* key)
	{
		if (*key == 0) return this;
		int next = toNumber(*key);
		if (children[next] == NULL) return NULL;
		return children[next]->find(key + 1);
	}
};