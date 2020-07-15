#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FOR(i,n,m) for(int i=(n); i<(m); i++)
#define endl "\n"
#define ll long long

int N, M;
vector<int> Tree;

void input()
{
	int min_len = 0;
	int max_len = 0;
	scanf("%d%d", &N, &M);
	FOR(i, 0, N)
	{
		int a;
		scanf("%d", &a);
		Tree.push_back(a);
		max_len = max(a, max_len);
	}

	ll sum = 0;
	int mid;
	while (min_len < max_len)
	{
		sum = 0;
		mid = (min_len + max_len) / 2;
		FOR(i, 0, N)
		{
			if (Tree[i] - mid > 0)
				sum += Tree[i] - mid;
		}
		if (sum > M)
			min_len = mid + 1;
		else if (sum < M)
		{
			max_len = mid;
			if (min_len >= max_len)
			{
				mid -= 1;
			}
		}
		else
			break;
		
	}
	printf("%d", mid);
}

int main()
{
	input();
	
	return 0;
}


/*
10 2
1 4 3 2 5 4 8 10 5 7

10 18
1 5 4 9 8 9 5 7 3 10

10 21
8 2 5 12 1 8 9 8 3 9
*/