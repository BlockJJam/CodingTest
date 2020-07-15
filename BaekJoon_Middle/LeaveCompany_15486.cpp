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
//#include <Windows.h>

using namespace std;
#define FOR(i,m,n) for(int i=(m); i<(n); i++)
#define endl "\n"

int N;
int S[1500001];
int P[1500001];
int cache[1500001];

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	FOR(i, 0, N)
	{
		cin >> S[i] >> P[i];
	}

	memset(cache, 0, sizeof(cache));
}

int main()
{
	input();

	int ans = 0;
	int shift_value = 0;
	int shift_index = 1;
	int next_value = 0;
	int next_index = 0;
	FOR(i, 0, N)
	{
		ans = ans < cache[i] ? cache[i] : ans;
		shift_value = cache[i];
		cache[i + 1] = cache[i + 1] < shift_value ? shift_value : cache[i + 1];

		next_value = cache[i] + P[i];
		next_index = i + S[i];
		if (next_index > N) continue;
		cache[next_index] = cache[next_index] < next_value ? next_value : cache[next_index];
	}
	ans = ans < cache[N] ? cache[N] : ans;

	/*FOR(i, 0, N)
		cout << cache[i] << " ";*/
	cout << ans;
	return 0;

}