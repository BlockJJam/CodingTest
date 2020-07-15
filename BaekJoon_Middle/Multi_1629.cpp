#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;

#define FOR(i,n,m) for(int i =(n); i<(m) ; i++)
#define ll long long


ll multi(int a, int b, int c)
{
	if (b == 1)
		return a%c;
	else
	{
		ll tmp = multi(a, b / 2, c);
		if (b % 2 == 0)								
			return (tmp*tmp) % c;					// b°¡ Â¦¼ö ÀÏ ¶§
		else
			return ((tmp*tmp) % c *a) % c;			// b°¡ È¦¼ö ÀÏ ¶§
	}
}

int main()
{

	int A, B, C;
	cin >> A >> B >> C;
	ll answer = multi(A, B, C);
	cout << answer << endl;
	
	return 0;
}