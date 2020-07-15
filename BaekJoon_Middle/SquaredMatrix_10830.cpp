#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

#define FOR(i,n,m) for(int i =(n); i<(m) ; i++)
#define ll long long
#define endl "\n"

int N;
ll B;

vector<vector<int>> squaredOper(vector<vector<int>> a, vector<vector<int>> b)
{
	vector<vector<int>> ret(N, vector<int>(N, 0));
	FOR(i, 0, N)
	{
		FOR(j, 0, N)
		{
			FOR(k, 0, N)
			{
				ret[i][j] += (a[i][k] * b[k][j])%1000;		
			}
			//cout << ret[i][j] << " ";
			ret[i][j] %= 1000;
		}
		//cout << endl;
	}
	return ret;
}

vector<vector<int>> squaredMatrix(ll b, vector<vector<int>> a)
{
	if (b == 1)
	{
		FOR(i, 0, N)
			FOR(j, 0, N)
			a[i][j] %= 1000;
		return a;
	}
	else
	{
		vector<vector<int>> tmp = squaredMatrix(b / 2, a);
		if (b % 2 == 0)
			return squaredOper(tmp, tmp);
		else
			return squaredOper(a, squaredOper(tmp, tmp));
	}
}

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> B;
	vector<vector<int>> A(N, vector<int>(N, 0));
	FOR(i, 0, N)
	{
		FOR(j, 0, N)
		{
			cin >> A[i][j];
		}
	}
	vector<vector<int>> answer = squaredMatrix(B, A);

	FOR(i, 0, N)
	{
		FOR(j, 0, N)
			cout << answer[i][j] << " ";
		cout << endl;
	}

}

int main()
{
	input();

	return 0;
}