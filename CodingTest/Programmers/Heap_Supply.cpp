#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;

	priority_queue<int> pq;
	int result = 0;
	int day = 0;
	for (int i = 0; i < k; i++)
	{
		if (day < dates.size() && dates[day] == i+1)
		{
			pq.push(supplies[day]);
		}


		if (day == dates.size()) continue;
		if (dates[day] == i + 1)
		{
			if (stock < k)
			{
				// 누적 stock이 k보다 작을 때 다음 공급날짜가 있다면
				if (day + 1 < dates.size())
				{
					if (stock < dates[day + 1]) continue;
					while (stock <= dates[day+1])
					{
						stock += pq.top();
					}
					result++;
				}
				// 다음 공급날짜가 없다면
				else
				{
					while (stock <= k - 1)
					{
						stock += pq.top();
					}
					result++;
				}
			}
			day++;
		}
		cout << stock << " ";
	}

	cout << result;
	answer = result;
	return answer;
}

int main()
{
	int stock = 4;
	vector<int> d({ 4,10,15 });
		vector<int> s({ 20,5,10 });
	int k = 30;

	int a = solution(stock, d, s, k);
}
