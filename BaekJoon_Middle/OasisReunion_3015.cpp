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
		cin >> height;							// 키를 입력
		pair<int, int> p{ height,1 };			// 키와 해당 키의 인원 pair
		while (!st.empty())					
		{
			if (st.back().first <= p.first)			// 스택에 있는 pair와 새로 줄 서는 p 중에 p의 키가 더 크거나 같은 경우
			{
				pair_count += st.back().second;		// 상대방이 더 크기 때문에 키를 증가 시킨다( 해당 키의 인원만큼)
				if (st.back().first == p.first)		
					p.second += 1;					// 같은 키를 가진 상대방이라면 해당 키의 인원 + 1
				st.pop_back();						// 비교한 스택 키는 이제 필요 없으므로 빼
			}
			else									// 상대방 키가 더 작다면
			{
				if (!st.empty())
					pair_count += 1LL;				// 일단 키를 하나 증가 시킨 후에 break( 이전 스택과 비교할 일이 없음 )
				break;
			}
		}
		st.push_back(p);							// 해당 p가 들어오고 쌍의 개수를 모두 구했다면 스택에 p 추가
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
	stack<pair<int, int> > st;                        // 키, 그 키를 가지는 인원

	for(int i = 0; i < n; i++){
		int high;
		cin >> high;
		pair<int,int> p = make_pair(high, 1);                // 키, 인원

		while(!st.empty()){
			if(st.top().first <= high){                // 자기보다 키가 큰 상대가 나타난 경우
				ans += (long long)st.top().second;        // 우선은 1을 증가시킨다. (키가 같더라도 1 증가 => 서로 마주보기 가능)
				if(st.top().first == high)            // 같다면
					p.second += st.top().second;        // 해당하는 인원을 증가시킨다.
				st.pop();                    // 자기보다 키가 큰 상대가 나타났기 때문에, 더 이상은 무의미하다. pop
			}
			else{
				if(!st.empty())                // 자기보다 키가 작은 상대가 나타남 (어깨 너머로 볼 수 있다)
					ans += 1LL;                // 서로 마주보기 가능
				break;
			}
		}
		st.push(p);                            // 첫 번째 사람, 자기보다 키가 더 작은 사람이 나타나면 push
	}
	cout << ans;
	return 0;
}


출처: https://redcoder.tistory.com/62 [로재의 개발 일기]

*/