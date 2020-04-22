//#include<iostream>
//#include<algorithm>
//#include<string>
//
//using namespace std;
//
//string cathe[102][102];
//
//string string_add(const string num1, const string num2)
//{
//	long long sum = 0;
//	string copy1(num1);
//	string copy2(num2);
//	string ret;
//
//	while (!copy1.empty() || !copy2.empty() || sum)
//	{
//		if (!copy1.empty())
//		{
//			sum += copy1.back() - '0';
//			copy1.pop_back();
//		}
//		if (!copy2.empty())
//		{
//			sum += copy2.back() - '0';
//			copy2.pop_back();
//		}
//		ret.push_back((sum % 10) + '0');
//		sum /= 10;
//	}
//	//cout << ret << endl;
//	reverse(ret.begin(), ret.end());
//	return ret;
//}
//
//string bino(const int n, const int m)
//{
//	string& ret = cathe[n][m];
//
//	if (ret != "")
//		return ret;
//	else if (n == m || m == 0)
//		return ret = '1';
//	else
//		return string_add(bino(n - 1, m), bino(n - 1, m - 1));
//}
//
//int main2()
//{
//	int n, m;
//	cin >> n >> m;
//	cout << bino(n, m);
//
//	return 0;
//}



 //기본 조합
#include <iostream>

using namespace std;

long long comb(int n, int k)
{
	if (k == n) return 1;
	else if (k == 1) return n;
	else return comb(n - 1, k - 1) + comb(n - 1, k);
}

int main()
{
	int n, k;
	cin >> n >> k;
	cout << comb(n, k) << endl;

	return 0;
}