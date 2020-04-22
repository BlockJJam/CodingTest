#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Truck
{
	int weight;
	int time;
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;

	int time = bridge_length;
	int rest_weight = 0;
	queue<Truck>q;
	for (int i = 0; i < truck_weights.size(); i++)
	{
		if (truck_weights[i] > weight) return answer;
		q.push({truck_weights[i],time});
	}
	
	//1초마다 다리 무게와 다리에 있는 트럭의 무게를 잰다 여유가 되면 트럭을 하나 더 올린다
	int total_time = 0;
	vector<Truck> timer;
	while (true)
	{
		if (q.empty())
			break;

		rest_weight += q.front().weight;
		timer.push_back({ q.front().weight,q.front().time });
		if (weight >= rest_weight)
			q.pop();
		else
		{
			timer.pop_back();
			rest_weight -= q.front().weight;
		}
		for (int i = 0; i < timer.size(); i++)
		{
			--timer[i].time;
			if (timer[i].time == 0)
			{
				rest_weight -= timer[i].weight;
			}
		}
		total_time++;
	}
	// 마지막 큐가 비어있다면 마지막 트럭이 출발한 것이므로 마지막 트럭이 이동한 시간만큼 더해준다
	total_time += bridge_length;
	cout << total_time;
	answer = total_time;

	return answer;
}

int main()
{
	int a, b;
	vector<int> c = { 10,10,10,10,10,10,10,10,10,10 };
	a = 100;
	b = 100;
	solution(a,b,c);
}