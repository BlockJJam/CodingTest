#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector <string> str_vec;
int solution(string s) {
	int answer = 0;
	s = "aabbaccc";
	string temp = s;
	
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 1; j < (s.size()-i) / 2; j++)
		{
			string s1(temp, i, j);
			for (int k = j; k < s.size() - j; k++)
			{
				if(string::npos != temp.find(s1,k))

			}
		}
	}
    
    return answer;
}

int main()
{
	string s;
}