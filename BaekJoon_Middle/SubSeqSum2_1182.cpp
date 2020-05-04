#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <bitset>
using namespace std;

long long N, S;
vector<long long> num_arr;
int sum_count = 0;
bool Selected[21];

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> S;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		num_arr.push_back(num);
	}
}

void calc()
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (Selected[i] == true)
		{
			sum += num_arr[i];
		}
	}
	//cout << sum << endl;
	if (sum == S)
		sum_count++;
}

void solve(int begin, int count)
{
	if (count == 0)
	{
		calc();
		return;
	}

	for (int i = begin; i < N; i++)
	{
		if (Selected[i] == true) continue;
		Selected[i] = true;
		solve(i, count - 1);
		Selected[i] = false;
	}
}

void print()
{
	cout << sum_count << endl;
}

int main()
{
	input();
	for (int i = 1; i <= N; i++)
	{
		solve(0, i);
		fill(&Selected[0], &Selected[0] + 21, 0);
	}
	print();

}