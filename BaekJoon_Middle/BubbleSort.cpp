// 버블정렬 예시 : 3 1 2 4 -> 1 3 2 4 -> 1 2 3 4  ( 첫 자리수 3을 기준으로 실행 ) 

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <bitset>
#include <cmath>
#include <unordered_map>
using namespace std;

#define FOR(i,n) for(int i=0; i<(n); i++)
const int MAX = 500001;

int N;
int arr[MAX];
int c_arr[MAX];
long swap_count = 0;

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	FOR(i, N)
	{
		cin >> arr[i];
	}
}

void mergeBubble(int left, int right)
{
	int mid = (left + right) / 2;
	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
		{
			c_arr[k++] = arr[i++];
		}
		else
		{
			swap_count += (j - k);
			c_arr[k++] = arr[j++];
		}
		
	}

	int temp = i > mid ? j : i;
	while (k <= right)
		c_arr[k++] = arr[temp++];

	for (int i = left; i <= right; i++)
		arr[i] = c_arr[i];
}

void partition(int left, int right)
{
	int mid;
	if (left < right)
	{
		
		mid = (left + right) / 2;
		partition(left, mid);
		partition(mid + 1, right);
		mergeBubble(left, right);
	}
}

void solve()
{
	partition(0, N - 1);
	/*FOR(i, N)
		cout << arr[i] << " ";
	cout << endl;*/
	cout << swap_count << endl;
}
int main()
{
	input();
	solve();

	return 0;
}