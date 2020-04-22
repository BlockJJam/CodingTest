#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

//다음 수열 함수
template<typename T>
bool next_perm(T first, T last)
{
	if (first == last) return false;
	T div_stand = last;
	if (first == --div_stand) return false;

	while (true)
	{
		T div1, div2;
		div1 = div_stand;
		div_stand--;

		if (*div_stand < *div1)
		{
			div2 = last;
			while (!(*div_stand < *--div2));
			std::iter_swap(div_stand, div2);
			std::reverse(div1, last);
			return true;
		}
		if (div_stand == first)
		{
			std::reverse(first, last);
			return false;
		}
	}
}
// 이전 수열 함수
template<typename T>
bool prev_perm(T first, T last)
{
	if (first == last) return false;
	T div_stand = last;
	if (first == --div_stand) return false;

	while (true)
	{
		T div1, div2;
		div1 = div_stand;
		div_stand--;

		if (*div_stand > *div1)
		{
			div2 = last;
			while (!(*div_stand > *--div2));
			std::iter_swap(div_stand, div2);
			std::reverse(div1, last);
			return true;
		}
		if (div_stand == first)
		{
			std::reverse(first, last);
			return false;
		}
	}
}
// 모든 순열
//int main()
//{
//	int n;
//	int check = 1;
//	vector<int> data;
//
//	cin >> n;
//
//	data.resize(n);
//
//	for (int i = 0; i < n; i++)
//		data[i] = i+1;
//
//	do
//	{
//		for (int e : data)
//			cout << e << " ";
//		cout << "\n";							// endl 쓰지 마라
//	} while (next_perm(data.begin(), data.end()));
//	return 0;
//}

//다음 순열
//int main()
//{
//	long long n;
//	int last_check = 1;
//	vector<int> data;
//	cin.clear();
//	cin >> n;
//
//	data.resize(n);
//
//	for (long long i = 0; i < n; i++)
//		cin >> data[i];
//
//	last_check = next_perm(data.begin(), data.end());
//	if (last_check)
//	{
//		for (long long i = 0; i < n; i++)
//			cout << data[i] << " ";
//	}
//	else
//		cout << -1;
//}

//이전 순열
int main1()
{
	long long n;
	int last_check = 1;
	vector<int> data;
	cin.clear();
	cin >> n;

	data.resize(n);

	for (long long i = 0; i < n; i++)
		cin >> data[i];

	last_check = prev_perm(data.begin(), data.end());
	if (last_check)
	{
		for (long long i = 0; i < n; i++)
			cout << data[i] << " ";
	}
	else
		cout << -1;

	return 0;
}
