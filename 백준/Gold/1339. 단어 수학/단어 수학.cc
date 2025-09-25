#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
using namespace std;
int n;
int arr[26]; // 알파벳 마다 가중치
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            int p = s.length() - j - 1;
            arr[s[j] - 'A'] += pow(10, p);
        }
    }
    sort(arr, arr + 26);
    int num = 9;
    int sum = 0;
    for (int i = 25; i >= 0; i--)
    {
        if (arr[i] == 0)
            break;
        sum += arr[i] * num;
        num--;
    }
    cout << sum;
}