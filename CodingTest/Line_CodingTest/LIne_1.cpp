#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>

using namespace std;

int solution(string inputString) {
	int answer = -1;

	vector<char> s1({ '{','(','[','<' });
	vector<char> s2({ '}',')',']','>' });

	int total_count = 0;
	int sum = 0;
	for (int i = 0; i < inputString.size(); i++)
	{
		for (int j = 0; j < s1.size(); j++)
		{
			if (inputString[i] == s1[j])
			{
				sum++;
				total_count++;
			}
			if (inputString[i] == s2[j])
			{
				sum--;
				if (sum < 0)
				{
					return -1;
				}
			}
		}
	}
	answer = total_count;

	return answer;
}




int main1()
{


	return 0;
}