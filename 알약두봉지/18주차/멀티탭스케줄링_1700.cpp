#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, K, order[101], cnt[101], last, ans;
vector<int> v;
int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 0; i < K; i++)
    {
        int a;
        scanf("%d", &a);
        cnt[a]++;
        order[i] = a;
    }

    for (int i = 0; i < K; i++)
    {
        int cur = order[i];
        bool chk = false;
        for (int j = 0; j < v.size(); j++)
            if (v[j] == cur) // �̹� �����ϸ�
            {
                chk = true;
                cnt[cur]--;
                break;
            }
        if (chk)
            continue;
        if (v.size() < N) // ���ڸ� ������
        {
            v.push_back(cur);
            cnt[cur]--;
            continue;
        }
        else // ���ڸ� ����
        {
            bool chk2 = false, chk3 = false;
            for (int j = 0; j < v.size(); j++)
            {
                if (cnt[v[j]] == 0) // ���� ���� ���� ����.
                {
                    v.erase(v.begin() + j);
                    chk2 = true;
                    ans++;
                    break;
                }
            }
            if (!chk2) // ���� ����
            {
                int vIdx, orderIdx = -1;
                for (int k = 0; k < v.size(); k++)
                {
                    for (int j = i + 1; j < K; j++)
                    {
                        if (order[j] == v[k]) // ���� ���߿� ����� �ܼ�Ʈ �̱�
                        {
                            if (orderIdx < j)
                            {
                                vIdx = k;
                                orderIdx = j;
                            }
                            chk3 = true;
                            break;
                        }
                    }
                }
                v.erase(v.begin() + vIdx);
                ans++;
            }
            if (!chk2 && !chk3)
            {
                v.erase(v.begin());
                ans++;
            }
            cnt[cur]--;
            v.push_back(cur);
        }
    }
    printf("%d", ans);
    return 0;
}