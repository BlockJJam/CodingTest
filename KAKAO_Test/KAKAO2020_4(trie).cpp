// �ڹ���� ����

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
#include <limits>
using namespace std;

#define FOR(i,m,n) for(int i=(m); i<(n); i++)

using namespace std;

const int TrieNode = 26; // Ʈ���� ��帶�� ������ ����( ���� - 10��, ���ĺ� -26��,

struct Trie
{
	Trie *next[TrieNode]; // ���� ��带 ����Ű�� ������ �迭
	int count;
	

	// ������
	Trie()
	{
		fill(next, next + TrieNode, nullptr);
		count =0;
	}

	// �Ҹ���
	~Trie()
	{
		for (int i = 0; i < TrieNode; i++)
			if (next[i])
				delete next[i];
	}

	// ���ڿ� key�� ���� ������ ����. ���� �� �ϰ����� �ִ����� ����
	void insert(const char *key)
	{
		count++;
		//cout << *key << " " << count << endl;
		// ���ڿ��� ���̶��
		if (*key == '\0')
		{
			return;
		}

		int nextKey = *key -'a';


		// �������� ���� Ʈ���̰� ���ٸ�
		if (!next[nextKey])
			next[nextKey] = new Trie;

		// ���� ����� count���� �ϳ� �߰��Ѵ�
		

		// ������� �Դٴ� �ǹ̴� Ʈ������ �ڽ��� �и��� �ִٴ°�.
		// �̶� �ڽĿ��� �ϰ����� ������ �������ų�
		// finish�� true��� �ϰ����� ���ٴ� �ǹ�.
		
		
		//next[nextKey]->count++;
		next[nextKey]->insert(key + 1);
		
		return;
	}

	// query�� ���󰡸鼭 �ش� query�� ������ �´� word ������ return
	int getCount(const char *key)
	{
		int nextKey = *key - 'a';
		//cout << *key << " " << count<< endl;
		int ret;
		if (*key == '?')
			return count;
		else
			if (!next[nextKey])
				return 0;
			else
				return ret = next[nextKey]->getCount(key + 1);
	}
};

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;

	int ws = words.size();
	int qs = queries.size();
	answer = vector<int>(qs, 0);
	bool Matched = false;
	int match_count = 0;

	vector<Trie> Root(10001);
	vector<Trie> revRoot(10001);
	FOR(i, 0, ws)
	{
		int str_s = words[i].size();
		Root[str_s].insert(words[i].c_str());

		reverse(words[i].begin(), words[i].end());
		revRoot[str_s].insert(words[i].c_str());
	}

	FOR(i, 0, qs)
	{
		int quer_s = queries[i].size();
		if (queries[i][0] == '?')
		{
			// ���λ簡  ?�̸�
			reverse(queries[i].begin(), queries[i].end());
			answer[i] = revRoot[quer_s].getCount(queries[i].c_str());
		}
		else
		{
			// ���̻簡 ?�̸�
			answer[i] = Root[quer_s].getCount(queries[i].c_str());
		}
	}

	
	/*FOR(i, 0, answer.size())
		cout << answer[i] << " ";*/
	return answer;
}

int main()
{
	vector<string> w({ "frodo", "front", "frost", "frozen", "frame", "kakao" });
	vector<string> q({ "fro??", "????o", "fr???", "fro???", "pro?" });
	solution(w, q);

	return 0;
}