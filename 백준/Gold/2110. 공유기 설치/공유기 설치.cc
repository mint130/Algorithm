#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, C;
long long ans;
long long arr[200001]; // 집의 좌표
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> C;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    // 가장 인접한 두 공유기 사이의 거리를 가능한 크게
    long long st = 1;
    long long en = arr[N - 1] - arr[0]; // 가장 인접한 두 공유기 사이의 거리는 최대 arr[N-1]-arr[0]
    while (st <= en)
    {
        long long mid = (st + en) / 2; // mid: 가장 인접한 두 공유기 사이 거리
        int cnt = 1;                   // cnt: 설치한 공유기 갯수
        int s = 0, e = 0;
        while (s <= e && e < N)
        {
            // 공유기 설치
            if (arr[e] - arr[s] < mid) // e와 s의 거리가 mid보다 작다 -> e 증가
            {
                e++;
            }
            else // e와 s의 거리가 mid보다 크거나 같다 -> cnt++, s=e
            {
                cnt++; // e에 공유기 설치
                s = e;
            }
        }
        if (cnt < C) // 공유기를 설치했는데 C보다 작다 -> en = mid-1
        {
            en = mid - 1;
        }
        else // 공유기를 설치했는데 C보다 크거나 같다 -> st = mid+1
        {
            ans = max(ans, mid);
            st = mid + 1;
        }
    }
    cout << ans;
}