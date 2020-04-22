#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>

using namespace std;

vector<vector<int>> n1;
vector<vector<int>> n2;
vector<int> ans_int;
priority_queue<int> pq;
int N;

void solve(int n, int m)
{
	if (m == 0)
	{
		// 출력기
		cout << 111 << endl;
		for (int i = 0; i < n2[0].size(); i++)
			cout << n2[0][i] << endl;
		int result=0;
		priority_queue<int> len_pq;
		int length;
		// 두 응시자의 지수를 검사
		for (int i = 0; i < n2[0].size(); i++)
		{
			if (n2[0][i] == n2[1][i])
			{
				result++;
				length++;
			}
			else
			{
				len_pq.push(length);
				length = 0;
			}
		}
		result = result + pow(len_pq.top(), 2);
		pq.push(result);


		while (!len_pq.empty()) 
			len_pq.pop();

		return;
	}
	// 출력기
	cout << 11 << endl;

	for (int i = 0; i < n; n++)
	{
		n2[N - m] = n1[i];
		
		n1.erase(n1.begin() + i);
		solve(n - 1, m - 1);
		n1.insert(n1.begin() + i, n2[N - m]);
	}
}

int solution(string answer_sheet, vector<string> sheets) {
	int answer = -1;
	// 출력기
	cout << 1 << endl;
	//vector int로 옮기기
	for (int i = 0; i < answer_sheet.size(); i++)
		ans_int.push_back(answer_sheet[i] - '0');

	n1 = vector<vector<int>>(sheets.size(), vector<int>(sheets[0].size(), 0));
	for (int i = 0; i < sheets.size(); i++)
	{
		for (int j = 0; j < sheets[i].size(); j++)
		{
			n1[i].push_back(sheets[i][j] - '0');
		}
	}
	N = 2;
	// 출력기
	cout << 1 << endl;
	n2 = vector<vector<int>>(2, vector<int>(sheets[0].size(),0));

	solve(sheets.size(), 2);

	cout << pq.top();

	return answer;
}




int main()
{
	string answer_sheet = "4132315142";

	vector<string> sheets({"3241523133", "4121314445", "3243523133", "4433325251", "2412313253"});
	solution(answer_sheet, sheets);

	return 0;
}