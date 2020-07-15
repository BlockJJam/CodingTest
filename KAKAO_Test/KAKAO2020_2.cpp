// °ýÈ£
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

string getCorrectString(string s)
{
	if (s.empty()) return "";

	bool isBal = false;
	int uv_div = 0;
	string u, v;
	FOR(i, 0, s.size())
	{
		if (s[0] == '(') isBal = true;
		else	isBal = false;

		if (s[i] == '(') uv_div += 1;
		else uv_div -= 1;

		if (uv_div == 0)
		{
			u = s.substr(0, i + 1);
			v = s.substr(i + 1, s.size() - (i + 1));
			break;
		}
	}
	cout << u << " " << v << endl;
	if (isBal == true)
	{
		string result ="";
		result += u;
		
		return result + getCorrectString(v);
	}
	else
	{
		string temp = '(' + getCorrectString(v) + ')';
		u = u.substr(1, u.size() - 2);
		FOR(i, 0, u.size())
		{
			if (u[i] == '(')
				u[i] = ')';
			else
				u[i] = '(';
		}
		return temp + u;
	}
	
}

string solution(string p) {
	string answer = "";

	answer =  getCorrectString(p);


	return answer;
}

int main()
{
	string s = "()))((()";
	cout << solution(s);

	return 0;
}
/*
"(()())()"	"(()())()"
")("	"()"
"()))((()"	"()(())()"
*/