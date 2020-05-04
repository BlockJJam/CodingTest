#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <bitset>
#include <cmath>
#include <unordered_map>
#include <queue>
#include <functional>
#include <cstring>
using namespace std;

vector<vector<int>> N_vec;
vector<int> select_vec;
int N, M;

#define FOR(i,n) for(int i=0; i<(n); i++)
#define endl "\n"
#define ll unsigned long long
const int MAX = 1000000;

void getUnion(int a,int b)
{
	vector<int> result;
	result.resize(N_vec[select_vec[a]].size() + N_vec[select_vec[b]].size());

	set_union(N_vec[select_vec[a]].begin(), N_vec[select_vec[a]].end(), N_vec[select_vec[b]].begin(), N_vec[select_vec[b]].end(), result.begin());

	/*for (auto e : result)
		cout << e << " ";
	cout <<"!" << endl;*/

	if (select_vec[a] < select_vec[b])
	{
		// N_vec[select_vec[b]]비워주고 select_vec[b] 를 a의 가리키는 번호로 변경
		N_vec[select_vec[a]] = result;
		int empty_vec = select_vec[b];

		FOR(i, N_vec[select_vec[b]].size())
			select_vec[N_vec[select_vec[b]][i]] = select_vec[a];

		N_vec[empty_vec] = { 0 };
		
	}
	else if( select_vec[a] > select_vec[b])
	{
		// N_vec[select_vec[b]]비워주고 select_vec[b] 를 a의 가리키는 번호로 변경
		N_vec[select_vec[b]] = result;
		int empty_vec = select_vec[b];

		FOR(i, N_vec[select_vec[a]].size())
			select_vec[N_vec[select_vec[a]][i]] = select_vec[b];

		N_vec[empty_vec] = { 0 };
	}
}

void getIncludes(int a, int b)
{
	bool isSameArray = false;

	if (select_vec[a] == select_vec[b])
		isSameArray = true;

	if (isSameArray)
		cout << "YES"<< endl;
	else
		cout << "NO" << endl;
}

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	N = N + 1;
	N_vec = vector<vector<int>>(N);
	//cout << N_vec.size() << endl;
	FOR(i, N)
	{
		N_vec[i].push_back(i);
		select_vec.push_back(i);
	}
	FOR(i, M)
	{
		int oper,a, b;
		cin >> oper >> a >> b;
		if (oper == 0)
			getUnion(a, b);
		else
			getIncludes(a, b);
	}	
}

int main()
{
	input();
	return 0;
}