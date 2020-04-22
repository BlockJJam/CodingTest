#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
using namespace std;

#define endl "\n"

long long N, K;
long long numCount = 9;
long long numLength = 1;
long long calK;
long long totalNum=0;
int result = 0;

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
}

void solve()
{
	calK = K;

	while (calK > numCount * numLength)
	{
		totalNum += numCount;
		calK -= numCount * numLength;
		numCount *= 10;
		numLength++;
	}
	// 9+99 +1 + 3 <-(calK-1/numLength) = totalNum =103
	totalNum += (calK - 1) / numLength + 1;
	
	if (totalNum > N) 
		result = -1;
	else
	{
		// totalNum인 103의 3자리수 중에서 몇번째 자리를 찾을 건지 temp에 넣어놓는다
		long long temp = (calK - 1) % numLength + 1;

		int tenten = 1;
		for (int i = 0; i < numLength - 1; i++)
			tenten *= 10;

		for (int i = 0; i < temp; i++)
		{
			result = totalNum / tenten;
			totalNum %= tenten;
			tenten /= 10;
		}
	}
	
	cout << result << endl;
}

int main()
{
	input();
	solve();

	return 0;
}