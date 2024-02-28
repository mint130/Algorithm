#include <iostream>
#include <map>

using namespace std;

map<int, string> number;
map<string, int> name;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	//N은 포켓몬의 수 M은 맞춰야 하는 문제의 수
	for (int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;
		number.insert({ i,s });
		name.insert({ s,i });

	}
	for (int i = 0; i < M; i++)
	{
		string s;
		cin >> s;
		int n=atoi(s.c_str()); //문자인지 숫자인지 판별, 문자라면 0 반환
		
		if (n == 0) //문자
		{
			auto it = name.find(s);
			if (it != name.end())
			{
				cout << it->second << "\n";
			}
		}
		else //숫자(key)
		{
			auto it = number.find(n);
			if (it != number.end())
			{
				cout << it->second << "\n";
			}
		}
	}
}