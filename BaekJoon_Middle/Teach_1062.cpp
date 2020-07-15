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

	#define FOR(i,n,m) for(int i=(n); i<(m); i++)
	#define endl "\n"

	int N, K;
	bool teach[26];
	vector<string> str_vec;
	int cnt=0;
	int answer=0;

	void read_check(string& s)
	{
		bool isRead = true;
		//cout << s << endl;
		for (char e : s)
		{
			//cout << e << " ";
			int word = e - 'a';
			if (teach[word] == false)
			{
				//cout << e << endl;
				isRead = false;
				break;
			}
		}
		if (isRead == true) cnt++;
	}

	void solve(int t_word, int t_cnt)
	{
	
		if (t_cnt == 0)
		{
			/*FOR(i, 0, 26)
				cout << teach[i] << " ";
			cout << endl;*/
			FOR(i, 0, str_vec.size())
			{
				read_check(str_vec[i]);
			}
			answer = answer > cnt ? answer : cnt;
			cnt = 0;
			return;
		}

		FOR(i, t_word, 26)
		{
			if (teach[i] == true)
				continue;
			teach[i] = true;
			solve(i+1, t_cnt - 1);
			teach[i] = false;
		}
	}
	// 수열로 K-5개의 소문자를 각 각 가르치면서 모든 수열로 가르친 글자를 가지고 단어를 검사

	void input()
	{
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		cin >> N >> K;
		
		string basic = "antic";
		for(char e : basic)
		{
			int word = e - 'a';
			teach[word] = true;
		}

		FOR(i, 0, N)
		{
			string s;
			cin >> s;
			str_vec.push_back(s);
		}

	}

	int main()
	{
		input();
		if (K == 26)
			answer = N;
		else if (K >= 5)
			solve(0, K - 5);
		else
			answer = 0;

		cout << answer;
		return 0;
	}