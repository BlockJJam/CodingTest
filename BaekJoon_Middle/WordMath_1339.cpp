#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
using namespace std;

#define endl "\n"

int N;
vector<string> str_vec;
vector<int> Alphabet(26, 0);
int result=0;


void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string a;
		cin >> a;
		str_vec.push_back(a);
	}
}

bool compareAlpha(int& A, int& B)
{
	if (A > B)
		return true;
	else
		return false;
}

void solve()
{
	for (int i = 0; i < str_vec.size(); i++)
	{
		int tenten = 1;
		for (int j = str_vec[i].size() - 1; j >= 0; j--)
		{
			int alpha_num = str_vec[i][j] - 'A';
			Alphabet[alpha_num] += tenten;
			tenten *= 10;
		}
	}
	
	sort(Alphabet.begin(), Alphabet.end(), compareAlpha);
	

	int giveNum = 9;
	while (giveNum >= 0)
	{
		Alphabet[9 - giveNum] *= giveNum;
		giveNum--;
	}
	for (int i = 0; i < Alphabet.size(); i++)
		result += Alphabet[i];
	
}

void print()
{
	cout << result << endl;
}


int main()
{
	input();
	solve();
	print();

	return 0;
}