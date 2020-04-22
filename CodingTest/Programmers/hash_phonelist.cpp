#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	unordered_map< int,string> phone_map;

	for (string e : phone_book)
	{
		if (phone_map.end() == phone_map.find(e.size()))
		{
			phone_map.insert(make_pair(e.size(), e));
		}
		else if (phone_map[e.size()] == e)
		{
			answer = false;
			break;
		}
	}
	vector<int> phone_size;
	for( int i=0; i< phone_book.size(); i++)
		phone_size.push_back(phone_book[i].size());

	sort(phone_size.begin(), phone_size.end());
	for (int i = 0; i<phone_size.size(); i++)
	{
		string std = phone_map[phone_size[i]];
		for (string e : phone_book)
		{
			if (std.size() > e.size()) continue;
			if (std != e && std == e.substr(0, phone_size[i]))
			{
				answer = false;
				break;
			}
		}

	}

	return answer;
}
int main()
{
	bool answer = solution(vector<string> ());
	cout << answer;
}