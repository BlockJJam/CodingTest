#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	//vector<int> c_arr;
	for (auto e : commands)
	{
		int i = e[0];
		int j = e[1];
		int k = e[2];
		cout << i << " " << j << " " << k << endl;

		vector<int> c_arr;
		for (int a = i - 1; a < j; a++)
			c_arr.push_back(array[a]);

		sort(c_arr.begin(), c_arr.end());

		answer.push_back(c_arr[k-1]);
	}

		return answer;
}

int main()
{
	solution({ 1,5,2,6,3,7,4 }, { {2, 5, 3},{4, 4, 1},{1, 7, 3} });
}