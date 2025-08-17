#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int ans;
int arr[10];     // 주사위 배열
int location[4]; // 현재 말의 위치
int map[35];     // 윷놀이 판
int turn[35];    // 방향 전환
int s[35];       // 윷놀이 판의 점수

void dfs(int idx, int score)
{
    if (idx == 10)
    {
        ans = max(score, ans);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int cur = location[i]; // 현재 말의 위치
        int mov = arr[idx];    // 이동할 수 있는 범위
        if (cur == 21)
            continue; // 40에서 시작하면 못고름

        int nxt = cur; // 도착하는 위치
        // 방향 전환해야 하는 위치
        if (turn[cur] > 0)
        {
            nxt = turn[nxt];
            mov -= 1;
        }
        for (int j = 0; j < mov; j++)
        {
            nxt = map[nxt];
        }
        // 도착점에 다른 말 있는지 확인
        bool flag = 0;
        for (int j = 0; j < 4; j++)
        {
            if (j == i)
                continue;
            if (location[j] == nxt && nxt != 21) // 40은 모두가 겹치는 곳
            {
                // 도착점에 다른 말 있음
                flag = 1;
                break;
            }
        }
        if (flag)
            continue;

        // 도착점에 다른 말 없는 경우
        location[i] = nxt;
        dfs(idx + 1, score + s[nxt]);
        location[i] = cur;
    }
}
void init()
{
    // map 초기화 (다음 도착하는 노드 번호 저장)
    for (int i = 0; i < 21; i++)
        map[i] = i + 1;
    map[21] = 21;
    for (int i = 22; i < 27; i++)
        map[i] = i + 1;
    map[28] = 29;
    map[29] = 30;
    map[30] = 25;
    map[31] = 32;
    map[32] = 25;
    map[27] = 20;

    turn[5] = 22;  // 10 파란 화살표
    turn[10] = 31; // 20 파란 화살표
    turn[15] = 28; // 30 파란 화살표
    turn[25] = 26; // 25는 무조건 위로

    // 번호
    for (int i = 0; i < 21; i++)
        s[i] = i * 2;
    s[22] = 13;
    s[23] = 16;
    s[24] = 19;

    s[31] = 22;
    s[32] = 24;
    s[28] = 28;

    s[29] = 27;
    s[30] = 26;
    s[25] = 25;
    s[26] = 30;
    s[27] = 35;
}
int main()
{
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    init();
    dfs(0, 0);
    cout << ans;
}