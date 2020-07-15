#include <string>
#include <vector>
#include <iostream>
using namespace std;
int total = -1;
bool visited[1000000];

int convertNN(int N)
{
	string str = to_string(N);
	string a = to_string(N % 10);
	str = str + a;
	int ret = stoi(str);
	//cout << "!!" << ret << endl;
	return ret;
}
void dfs(int N, int num, int result, int cnt)
{
	//cout << result << " ";
	if (result == 0) return;
	if (cnt > 8) return;
	if (result == num)
	{
		if (total == -1) total = cnt;
		else
			total = total < cnt ? total : cnt;
		//cout << endl;
		//cout << "??" << total << endl;
		return;
	}


	int tmp;
	// +
	tmp = result + N;
	if (visited[tmp] == false)
	{
		visited[tmp] = true;
		dfs(N % 10, num, tmp, cnt + 1);
		visited[tmp] = false;
	}


	// -
	tmp = result - N;
	if (tmp > 0)
	{
		if (visited[tmp] == false)
		{
			visited[tmp] = true;
			dfs(N % 10, num, tmp, cnt + 1);
			visited[tmp] = false;

		}
	}
	tmp = N - result;
	if (tmp > 0)
	{
		if (visited[tmp] == false)
		{
			visited[tmp] = true;
			dfs(N % 10, num, tmp, cnt + 1);
			visited[tmp] = false;

		}
	}

	// *
	tmp = result * N;
	if (tmp < 1000000)
	{
		if (visited[tmp] == false)
		{
			visited[tmp] = true;
			dfs(N % 10, num, tmp, cnt + 1);
			visited[tmp] = false;

		}
	}


	// /
	tmp = result / N;
	if (visited[tmp] == false)
	{
		visited[tmp] = true;
		dfs(N % 10, num, tmp, cnt + 1);
		visited[tmp] = false;
	}
	tmp = N / result;
	if (visited[tmp] == false)
	{
		visited[tmp] = true;
		dfs(N % 10, num, tmp, cnt + 1);
		visited[tmp] = false;
	}

	// NN
	tmp = convertNN(N);
	if (tmp < 1000000)
	{
		dfs(tmp, num, result, cnt + 1);
	}
}

int solution(int N, int number) {
	int answer = 0;
	visited[N] = true;
	dfs(N, number, N, 1);


	answer = total;
	cout << "a" << answer << endl;
	return answer;
}
int main()
{
	solution(5, 12);
	return 0;
}