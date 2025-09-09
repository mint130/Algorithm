#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int arr[100001];
int st, en;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        en += arr[i];
        st = max(arr[i], st);
    }
    // en -> 강의 길이의 합
    // st -> 가장 긴 강의
    while (st <= en)
    {
        int mid = (st + en) / 2; // 한 블루레이의 크기
        int sum = 0;
        int cnt = 1;
        for (int i = 0; i < n; i++)
        {
            // 블루레이의 크기가 mid보다 커지면 cnt 증가
            if (sum + arr[i] <= mid)
            {
                sum += arr[i];
            }
            else
            {
                cnt++;
                sum = arr[i];
            }
        }
        if (cnt <= m)
        {
            // 블루레이 크기 줄임
            en = mid - 1;
        }
        else
        {
            // 블루레이 크기 늘림
            st = mid + 1;
        }
    }
    cout << st;
}