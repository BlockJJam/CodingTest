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

int N, Q;

bool result = false;

struct Trie
{
	Trie *go[26];
	Trie *fail;
	bool output;

	Trie()
	{
		fill(go, go + 26, nullptr);
		output = false;
	}

	~Trie()
	{
		for (int i = 0; i < 26; i++)
			if (go[i])
				delete go[i];
	}

	void insert(const char *key)
	{
		if (*key == '\0')
		{
			output = true;
			return;
		}

		int next = *key - 'a';
		if (!go[next])
			go[next] = new Trie;

		go[next]->insert(key + 1);
	}
};

void solve()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char str[10001];

	Trie *root = new Trie;

	cin >> N;
	FOR(i, 0, N)
	{
		cin >> str;
		root->insert(str);
	}

	queue<Trie*> q;
	root->fail = root;
	q.push(root);

	while (!q.empty())
	{
		Trie *current = q.front();
		q.pop();

		FOR(i, 0, 26)
		{
			Trie* next = current->go[i];
			if (!next)
				continue;

			if (current == root)
				next->fail = root;
			else
			{
				Trie *dest = current->fail;

				while (dest != root && !dest->go[i])
					dest = dest->fail;

				if (dest->go[i])
					dest = dest->go[i];
				next->fail = dest;
			}
			if (next->fail->output)
				next->output = true;

			q.push(next);
		}
	}

	cin >> Q;
	FOR(i, 0, Q)
	{
		cin >> str;
		Trie* current = root;
		result = false;

		for (int c = 0; str[c]; c++)
		{
			int next = str[c] - 'a';
			while (current != root && !current->go[next])
				current = current->fail;

			if (current->go[next])
				current = current->go[next];

			if (current->output)
			{
				result = true;
				break;
			}
		}
		puts(result ? "YES" : "NO");
	}

	delete root;
}

int main()
{
	solve();

	return 0;
}

/*
10 
ksjhdkfjahlhksjhdkfjahlhasdas
ksjhdkfjahlhsdlkjiaslj
lajsidjkajdbwkdjbkjbw
lskdnibaojdksjhdkfjahlh
skjdnfwbakjdshiuadiwb
skjdnfwbakjdshiuadiwbskjdnfwbakjdshiuadiwb
skjdnfwbakjdshiuadiwbsdhaoihwfhaodf
skjdnfwbakjdshiuadiwblsknadowndkjds
sdkdkwnodknowfodkw
poqwieuorikokjbvkb
10
afdasfasdfasdfsadfadsvadvdababfbadbadksjhdkfjahlhksjhdkfjahlhasdas
asfbdfsbsdfbsdfbdsfbsgfbzcvbnhjmjmkksjhdkfjahlhsdlkjiaslj
fghfggncvbdfgdtgdfvbcvbajsidjkajdbwkdjbkjbw
vbcvbghnhjmghfbsfregfdgdgdfdflskdnibaojdksjhdkfjahlh
dbcbvhnfghdggdfgdfgdfskjdnfwbakjdshiuadiwb
gdbdvbcvbdfskjdnfwbakjdshiuadiwbskjdnfwbakjdshiuadiwdfgdfgdfgdfgdfgdf
fgfgdfgdfgrdfgdfgdghgkjdnfwbakjdshiuadiwbsdhaoihwfhaodf
dfgjugdfgdfgdfggskjdnfwbakjdshiuadiwblsknadowndkjds
dfgrdgfdgdsdkdkwnodkngrgfgdfgrgdfgowfodkw
dfgdfgrgdfgdfgrgdgrhhyjujujyhtggregpoqwieuorikokjbvkb

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

int N, Q;

bool result = false;

struct Trie
{
	Trie *go[26];
	Trie *fail;
	bool output;

	Trie()
	{
		fill(go, go + 26, nullptr);
		output = false;
	}

	~Trie()
	{
		for(int i=0; i<26; i++)
			if (go[i])
				delete go[i];
	}

	void insert(const char *key)
	{
		if (*key == '\0')
		{
			output = true;
			return;
		}

		int next = *key - 'a';
		if (!go[next])
			go[next] = new Trie;

		go[next]->insert(key + 1);
	}
};

void solve()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char str[10001];

	Trie *root = new Trie;

	cin >> N;
	FOR(i, 0, N)
	{
		scanf("%s", str);
		root->insert(str);
	}

	queue<Trie*> q;
	root->fail = root;
	q.push(root);

	while (!q.empty())
	{
		Trie *current = q.front();
		q.pop();

		FOR(i, 0, 26)
		{
			Trie* next = current->go[i];
			if (!next)
				continue;

			if (current == root)
				next->fail = root;
			else
			{
				Trie *dest = current->fail;

				while (dest != root && !dest->go[i])
					dest = dest->fail;

				if (dest->go[i])
					dest = dest->go[i];
				next->fail = dest;
			}
			if (next->fail->output)
				next->output = true;

			q.push(next);
		}
	}

	cin >> Q;
	FOR(i, 0, Q)
	{
		cin >> str;
		Trie* current = root;
		result = false;

		for (int c = 0; str[c]; c++)
		{
			int next = str[c] - 'a';
			while (current != root && !current->go[next])
				current = current->fail;

			if (current->go[next])
				current = current->go[next];

			if (current->output)
			{
				result = true;
				break;
			}
		}
		string answer = result == true ? "YES" : "NO";
		cout << answer << endl;
	}

	delete root;
}

int main()
{
	solve();

	return 0;
}

*/