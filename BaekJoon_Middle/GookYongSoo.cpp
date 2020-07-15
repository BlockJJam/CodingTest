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
#include <limits>
using namespace std;

#define FOR(i,m,n) for(int i=(m); i<(n); i++)
#define endl "\n"
int N;
struct Student
{
	string name;
	int gook;
	int yong;
	int soo;

};
vector<Student> grade;

void input()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	FOR(i, 0, N)
	{
		string a;
		int b, c, d;
		cin >> a >> b >> c >> d;
		Student key{ a,b,c,d };
		grade.push_back(key);
	}

}

bool compareStudent(Student& A, Student& B)
{
	if (A.gook == B.gook)
	{
		if (A.yong == B.yong)
		{
			if (A.soo == B.soo)
			{
				return A.name < B.name;
			}
			else
				return A.soo > B.soo;
		}
		else
			return A.yong < B.yong;
	}
	else
		return A.gook > B.gook;
}

void solve()
{
	//cout << grade.size() << endl;
	sort(grade.begin(), grade.end(), compareStudent);
	FOR(i, 0, N)
	{
		cout << grade[i].name << "\n";
	}
}

int main()
{
	input();
	solve();

	return 0;
}

/*
13
Junkyu 50 60 100
Sangkeun 80 60 50
Sunyoung 80 70 100
Soong 50 60 90
Haebin 50 60 100
Kangsoo 60 80 100
Donghyuk 80 60 100
Sei 70 70 70
Wonseob 70 70 90
Sanghyun 70 70 80
nsj 80 80 80
Taewhan 50 60 90
Sunyoungs 80 70 100
*/