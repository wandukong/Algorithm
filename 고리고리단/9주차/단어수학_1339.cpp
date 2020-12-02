#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

int N, ans;
string s;
int arr[26];

int main()
{
    scanf("%d", &N);
    while (N--)
    {
        cin >> s;
        for (int i = 0; i < s.size(); i++)
            arr[s[i] - 'A'] += pow(10, s.size() - 1 - i);
    }

    sort(arr, arr + 26, greater<int>());
    for (int i = 0; i < 10; i++)
    {
        ans += arr[i] * (9 - i);
        printf("%d\n", arr[i] * (9 - i));
    }
    printf("%d\n", ans);
    return 0;
}