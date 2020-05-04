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

#define FOR(i,n) for(int i=0; i<(n); i++)
#define endl "\n"
#define ll unsigned long long
const int MAX = 500001;

int N;
vector<pair<int, int>> st;
ll pair_count=0;

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	FOR(i, N)
	{
		int height;
		cin >> height;							// Ű�� �Է�
		pair<int, int> p{ height,1 };			// Ű�� �ش� Ű�� �ο� pair
		while (!st.empty())					
		{
			if (st.back().first <= p.first)			// ���ÿ� �ִ� pair�� ���� �� ���� p �߿� p�� Ű�� �� ũ�ų� ���� ���
			{
				pair_count += st.back().second;		// ������ �� ũ�� ������ Ű�� ���� ��Ų��( �ش� Ű�� �ο���ŭ)
				if (st.back().first == p.first)		
					p.second += 1;					// ���� Ű�� ���� �����̶�� �ش� Ű�� �ο� + 1
				st.pop_back();						// ���� ���� Ű�� ���� �ʿ� �����Ƿ� ��
			}
			else									// ���� Ű�� �� �۴ٸ�
			{
				if (!st.empty())
					pair_count += 1LL;				// �ϴ� Ű�� �ϳ� ���� ��Ų �Ŀ� break( ���� ���ð� ���� ���� ���� )
				break;
			}
		}
		st.push_back(p);							// �ش� p�� ������ ���� ������ ��� ���ߴٸ� ���ÿ� p �߰�
	}
	cout << pair_count << endl;
}


int main()
{
	input();

	return 0;

}
/*

#include<iostream>
#include<stack>

using namespace std;

int main(void){
	int n;
	cin >> n;
	long long ans = 0;
	stack<pair<int, int> > st;                        // Ű, �� Ű�� ������ �ο�

	for(int i = 0; i < n; i++){
		int high;
		cin >> high;
		pair<int,int> p = make_pair(high, 1);                // Ű, �ο�

		while(!st.empty()){
			if(st.top().first <= high){                // �ڱ⺸�� Ű�� ū ��밡 ��Ÿ�� ���
				ans += (long long)st.top().second;        // �켱�� 1�� ������Ų��. (Ű�� ������ 1 ���� => ���� ���ֺ��� ����)
				if(st.top().first == high)            // ���ٸ�
					p.second += st.top().second;        // �ش��ϴ� �ο��� ������Ų��.
				st.pop();                    // �ڱ⺸�� Ű�� ū ��밡 ��Ÿ���� ������, �� �̻��� ���ǹ��ϴ�. pop
			}
			else{
				if(!st.empty())                // �ڱ⺸�� Ű�� ���� ��밡 ��Ÿ�� (��� �ʸӷ� �� �� �ִ�)
					ans += 1LL;                // ���� ���ֺ��� ����
				break;
			}
		}
		st.push(p);                            // ù ��° ���, �ڱ⺸�� Ű�� �� ���� ����� ��Ÿ���� push
	}
	cout << ans;
	return 0;
}


��ó: https://redcoder.tistory.com/62 [������ ���� �ϱ�]

*/