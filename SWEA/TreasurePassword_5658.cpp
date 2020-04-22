#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
#define endl "\n";

int N, T, K;
string sample;
set<ll> k_seq;
vector<ll> k_vec;

vector<ll> result;

ll desc(int a, int b)
{
	return a > b;
}

void solve()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j += (N/4))
		{
			string s (sample.begin()+j, sample.begin()+j+(N/4));
			ll hex_num = stoll(s, 0, 16);
			k_seq.insert(hex_num);
		}

		char c = sample[N - 1];
		sample.pop_back();
		sample.insert(0, 1, c);
	}
	// k_seq를 가지고 vector에 옮기기

	k_vec = vector<ll>(k_seq.size());
	copy(k_seq.begin(), k_seq.end(), k_vec.begin());
	sort(k_vec.begin(), k_vec.end(), desc);
}

void input()
{
	cin >> N >> K;
	
	cin >> sample;
}

int main()
{
	/*FILE *f;
	freopen_s(&f, "sample_input.txt", "r", stdin);*/

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		input();
		solve();


		result.push_back(k_vec[K - 1]);
		//cout << k_vec[K - 1];
		k_seq.clear();
		k_vec.clear();
	}

	for (int i = 0; i < T; i++)
		cout << "#" << i + 1 << " " << result[i] << endl;

	return 0;
}