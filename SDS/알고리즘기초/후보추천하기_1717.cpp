#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<int> v;
int cnt[101];
bool chk[101];

int main()
{
    scanf("%d", &N);
    scanf("%d", &M);
    while (M--)
    {
        int a;
        scanf("%d", &a);
        if (chk[a]) // 이미 들어가 잇음
        {
            cnt[a]++;
        }
        else // 처음 등장
        {
            if (v.size() < N)
            {
                v.push_back(a);
                cnt[a]++;
                chk[a] = true;
            }
            else
            {
                int targetIdx = 0, targetCnt = 987654321;
                for (int i = 0; i < N; i++)
                {
                    if (cnt[v[i]] < targetCnt)
                    {
                        targetCnt = cnt[v[i]];
                        targetIdx = i;
                    }
                }
                chk[v[targetIdx]] = false;
                cnt[v[targetIdx]] = 0;
                v.erase(v.begin() + targetIdx);
                v.push_back(a);
                cnt[a]++;
                chk[a] = true;
            }
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        printf("%d ", v[i]);
}