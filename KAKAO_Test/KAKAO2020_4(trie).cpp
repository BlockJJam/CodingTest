// 자물쇠와 열쇠

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

const int TrieNode = 26; // 트라이 노드마다 포인터 개수( 숫자 - 10개, 알파벳 -26개,

struct Trie
{
	Trie *next[TrieNode]; // 다음 노드를 가리키는 포인터 배열
	int count;
	

	// 생성자
	Trie()
	{
		fill(next, next + TrieNode, nullptr);
		count =0;
	}

	// 소멸자
	~Trie()
	{
		for (int i = 0; i < TrieNode; i++)
			if (next[i])
				delete next[i];
	}

	// 문자열 key를 현재 노드부터 삽입. 삽입 후 일관성이 있는지를 리턴
	void insert(const char *key)
	{
		count++;
		//cout << *key << " " << count << endl;
		// 문자열의 끝이라면
		if (*key == '\0')
		{
			return;
		}

		int nextKey = *key -'a';


		// 다음으로 가는 트라이가 없다면
		if (!next[nextKey])
			next[nextKey] = new Trie;

		// 현재 노드의 count수를 하나 추가한다
		

		// 여기까지 왔다는 의미는 트라이의 자식이 분명히 있다는것.
		// 이때 자식에서 일관성이 없던게 밝혀지거나
		// finish가 true라면 일관성이 없다는 의미.
		
		
		//next[nextKey]->count++;
		next[nextKey]->insert(key + 1);
		
		return;
	}

	// query를 따라가면서 해당 query와 조건이 맞는 word 개수를 return
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
			// 접두사가  ?이면
			reverse(queries[i].begin(), queries[i].end());
			answer[i] = revRoot[quer_s].getCount(queries[i].c_str());
		}
		else
		{
			// 접미사가 ?이면
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