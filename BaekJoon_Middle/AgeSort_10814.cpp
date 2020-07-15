#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(i,n,m) for(int i=(n); i<(m); i++)
#define endl "\n"

int N;
vector<vector<string>> user(201);

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	string name;
	int age;

	FOR(i, 0, N)
	{
		cin >> age >> name;
		//cout << age << " " << name << endl;
		user[age].push_back(name);
	}
	
	FOR(i, 0, user.size())
	{
		FOR(j, 0, user[i].size())
		{
			cout << i << " " << user[i][j] << endl;
		}
	}

}

int main()
{
	input();
	
	return 0;
}