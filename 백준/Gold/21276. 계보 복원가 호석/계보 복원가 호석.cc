#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
int n, m;
int in[1001];        // indegree가 0이면 root
vector<int> v[1001]; // v[조상]에 자식들 넣음
vector<string> family[1001];
map<string, int> num;  // 이름의 번호
map<int, string> name; // 번호의 이르
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        num[s] = i;  // 이름의 번호 저장
        name[i] = s; // 번호의 이름 저장
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        // s1의 조상 s2
        int child = num[s1];
        int parent = num[s2];
        v[parent].push_back(child);
        in[child]++; // 자식의 in ++
    }
    int k = 0;
    queue<int> q;
    vector<string> init; // 초기 가문
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
            // family[i].push_back(name[i]);
            init.push_back(name[i]);
        }
    }
    // 초기 가문 출력
    sort(init.begin(), init.end());
    cout << init.size() << "\n";
    for (auto s : init)
    {
        cout << s << " ";
    }
    cout << "\n";

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto nxt : v[cur])
        {
            in[nxt]--;
            if (in[nxt] == 0)
            {
                q.push(nxt);
                family[cur].push_back(name[nxt]);
            }
        }
    }

    // family 내부에서 사전 순으로 sort
    for (int i = 1; i <= n; i++)
    {
        sort(family[i].begin(), family[i].end());
    }

    for (auto i : num)
    {
        string s = i.first;
        int k = i.second;
        cout << s << " " << family[k].size() << " ";
        for (int j = 0; j < family[k].size(); j++)
        {
            cout << family[k][j] << " ";
        }
        cout << "\n";
    }

}