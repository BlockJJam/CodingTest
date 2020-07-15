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

string target, pattern, c_str;
int n, m;

vector <string> str_vec;
int solution(string s) {
	int answer = 1001;

	target = s;
	n = target.size();
	
	FOR(d, 1, (n / 2)+1)
	{
		int index = 0;

		for(int i =0; i<n; i += index)
		{
			string pattern = target.substr(i, d);
			cout << "pat: " << pattern << endl;
			int p_count = 1;
			for (int j = i + d ; j <= n; j += d)
			{
				if (j + d > n)
				{
					index = p_count*d ;
					break;
				}

				if (pattern == target.substr(j, d))
					p_count++;
				else
				{
					index = p_count*d ;
					break;
				}
			}
			if (p_count == 1)
			{
				index = 1;
				c_str += target[i];
				cout << c_str << endl;
			}
			else
			{
				c_str += to_string(p_count) + pattern;
				cout << c_str << endl;
				cout << "index: " << index << endl;
			}
		}

		answer = answer > c_str.size() ? c_str.size() : answer;
		c_str = "";
	}
	
    
    return answer;
}

int main()
{
	string s= "xababcdcdababcdcd";
	cout << solution(s);
	
}

/*
"aabbaccc"	7
"ababcdcdababcdcd"	9
"abcabcdede"	8
"abcabcabcabcdededededede"	14
"xababcdcdababcdcd"
*/