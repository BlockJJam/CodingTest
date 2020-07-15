#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int TrieNode = 26; // 트라이 노드마다 포인터 개수( 숫자 - 10개, 알파벳 -26개,

struct Trie
{
	Trie *next[TrieNode]; // 다음 노드를 가리키는 포인터 배열
	bool finish; // 이 노드에서 끝나는 전화번호가 있는가?
	bool nextChild; // 이 노드의 자식이 있는가?

	// 생성자
	Trie()
	{
		fill(next, next + TrieNode, nullptr);
		finish = nextChild = false;
	}

	// 소멸자
	~Trie()
	{
		for (int i = 0; i < TrieNode; i++)
			if (next[i])
				delete next[i];
	}

	// 문자열 key를 현재 노드부터 삽입. 삽입 후 일관성이 있는지를 리턴
	bool insert(const char *key)
	{
		// 문자열의 끝이라면
		if (*key == '\0')
		{
			finish = true;

			// 문자열이 끝났는데도
			// 자식이 있다면 일관성이 없다.
			if (nextChild)
				return 0;
			else
				return 1;
		}

		int nextKey = *key - 'a';

		// 다음으로 가는 트라이가 없다면
		if (!next[nextKey])
			next[nextKey] = new Trie;

		nextChild = true;

		// 여기까지 왔다는 의미는 트라이의 자식이 분명히 있다는것.
		// 이때 자식에서 일관성이 없던게 밝혀지거나
		// finish가 true라면 일관성이 없다는 의미.
		bool get = next[nextKey]->insert(key + 1);

		return !finish && get;
	}
};

