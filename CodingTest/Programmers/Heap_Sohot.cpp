#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <functional>
using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;

	vector<int> c_sco;
	std::priority_queue<int, std::vector<int>, std::greater<int> > pq;

	for (int i = 0; i < scoville.size(); i++)
		c_sco.push_back(scoville[i]);

	for (int i = 0; i < c_sco.size(); i++)
		pq.push(c_sco[i]);

	int k_count = 0;
	while (!pq.empty())
	{
		//음식을 꺼내 조합
		int k1 = pq.top();
		pq.pop();

		if (k1 >= K)
			break;

		if (pq.empty())
		{
			return -1;
		}
		int k2 = pq.top();
		pq.pop();

		int k_sum = k1 + (k2 * 2);
		if (k_sum < K)
			pq.push(k_sum);
		cout << k1 << "," << k2 << endl;
		k_count++;
	}

	answer += k_count;

	return answer;
}