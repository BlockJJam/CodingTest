// ÀÚ¹°¼è¿Í ¿­¼è

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

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;

	int ws = words.size();
	int qs = queries.size();
	answer = vector<int>(qs, 0);
	bool Matched = false;
	int match_count = 0;

	FOR(i, 0, qs)
	{
		FOR(j, 0, ws)
		{
			if (words[j].size() == queries[i].size())
			{
				if (queries[i][0] != '?')
				{
					FOR(k, 0, queries[i].size())
					{
						if (queries[i][k] == '?') break;
						if (queries[i][k] == words[j][k])
							Matched = true;
						else
						{
							Matched = false;
							break;
						}
					}
					if (Matched == true)
						++match_count;
				}
				else
				{
					for (int k = queries[i].size() - 1; k >= 0; k--)
					{
						if (queries[i][k] == '?') break;
						if (queries[i][k] == words[j][k])
							Matched = true;
						else
						{
							Matched = false;
							break;
						}
					}
					if (Matched == true)
						++match_count;
				}
			}
			else
				Matched = false;
		}
		answer[i] = match_count;
		match_count = 0;
	}
	
	FOR(i,0,answer.size())
		cout << answer[i] << " ";
	return answer;
}

int main()
{
	vector<string> w({ "frodo", "front", "frost", "frozen", "frame", "kakao"});
	vector<string> q({ "fro??", "????o", "fr???", "fro???", "pro?" });
	solution(w, q);

	return 0;
}