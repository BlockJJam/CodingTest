#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <unordered_map>
using namespace std;

unordered_map<string, int> snap_map;

bool compare(vector<string>& a, vector<string>& b)
{
	if (a[0] < b[0])
		return true;
	return false;
}

vector<vector<string>> solution(vector<vector<string>> snapshots, vector<vector<string>> transactions) {
	vector<vector<string>> answer;
	//snap			: 0 계좌이름, 1 잔액
	//transaction	: 0 id, 1 종류, 2 계좌이름, 3 금액

	for (int i = 0; i < snapshots.size(); i++)
	{
		if (snap_map.end() == snap_map.find(snapshots[i][0]))
		{
			snap_map.insert(make_pair(snapshots[i][0], 0));
		}
		else
			snap_map[snapshots[i][0]] ++;
	}

	vector<string> tran_id;

	for (int i = 0; i < transactions.size(); i++)
	{
		if (snap_map.end() == snap_map.find(transactions[i][2]))
		{
			snap_map.insert(make_pair(transactions[i][2], 0));
			if (transactions[i][1] == "SAVE")
				snapshots.push_back({ transactions[i][2], transactions[i][3] });
		}
		for (int j = 0; j < snapshots.size(); j++)
		{
			if (snapshots[j][0] == transactions[i][2])
			{
				for (int k = 0; k < tran_id.size(); k++)
					if (tran_id[k] == transactions[i][0])
						snap_map[snapshots[j][0]] = trana

				if (snap_map[snapshots[j][0]] == stoi(transactions[i][0]))
					continue;
				if (transactions[i][1] == "SAVE")
				{
					int snap = stoi(snapshots[j][1]);
					int tran = stoi(transactions[i][3]);
					snapshots[j][1] = to_string(snap + tran);
				}
				else
				{
					int snap = stoi(snapshots[j][1]);
					int tran = stoi(transactions[i][3]);
					snapshots[j][1] = to_string(snap - tran);
				}
				snap_map[snapshots[j][0]]++;
			}
		}
		tran_id.push_back(transactions[i][0]);
	}
	
	sort(snapshots.begin(), snapshots.end(), compare);
	answer = snapshots;
	return answer;
}




int main4()
{



	return 0;
}