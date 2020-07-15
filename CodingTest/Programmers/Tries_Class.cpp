#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int TrieNode = 26; // Ʈ���� ��帶�� ������ ����( ���� - 10��, ���ĺ� -26��,

struct Trie
{
	Trie *next[TrieNode]; // ���� ��带 ����Ű�� ������ �迭
	bool finish; // �� ��忡�� ������ ��ȭ��ȣ�� �ִ°�?
	bool nextChild; // �� ����� �ڽ��� �ִ°�?

	// ������
	Trie()
	{
		fill(next, next + TrieNode, nullptr);
		finish = nextChild = false;
	}

	// �Ҹ���
	~Trie()
	{
		for (int i = 0; i < TrieNode; i++)
			if (next[i])
				delete next[i];
	}

	// ���ڿ� key�� ���� ������ ����. ���� �� �ϰ����� �ִ����� ����
	bool insert(const char *key)
	{
		// ���ڿ��� ���̶��
		if (*key == '\0')
		{
			finish = true;

			// ���ڿ��� �����µ���
			// �ڽ��� �ִٸ� �ϰ����� ����.
			if (nextChild)
				return 0;
			else
				return 1;
		}

		int nextKey = *key - 'a';

		// �������� ���� Ʈ���̰� ���ٸ�
		if (!next[nextKey])
			next[nextKey] = new Trie;

		nextChild = true;

		// ������� �Դٴ� �ǹ̴� Ʈ������ �ڽ��� �и��� �ִٴ°�.
		// �̶� �ڽĿ��� �ϰ����� ������ �������ų�
		// finish�� true��� �ϰ����� ���ٴ� �ǹ�.
		bool get = next[nextKey]->insert(key + 1);

		return !finish && get;
	}
};

