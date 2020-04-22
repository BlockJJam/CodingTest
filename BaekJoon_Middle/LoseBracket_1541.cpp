#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
using namespace std;

string str;
int sum=0;
bool isPlus=true;

void input()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> str;
}

void calc(int temp)
{
	if (isPlus == true)
		sum += temp;
	else
		sum -= temp;
}

void solve()
{
	int temp = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '-')
		{
			calc(temp);
			temp = 0;

			isPlus = false;
		}
		else if (str[i] == '+')
		{
			calc(temp);
			temp = 0;
		}
		else
		{
			temp *= 10;
			temp += str[i] - '0';
		}
	}
	calc(temp);
	temp = 0;

	cout << sum << endl;
}

int main()
{
	input();
	solve();

	return 0;
}