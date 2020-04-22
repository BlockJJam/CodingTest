#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

bool compare(const string &a,const string&b)
{
	if (b + a < a + b)
		return true;
	return false;
}

string solution(vector<int> numbers) {
	string answer = "";

	vector<string> string;
	
	for (int e : numbers)
	{
		string.push_back(to_string(e));
	}

	sort(string.begin(), string.end(), compare);
	for (auto e : string) 
	{
		answer += e;
		cout << answer << endl;
	}
	

	if (answer[0] == '0')
		answer = "0";
	return answer;
}