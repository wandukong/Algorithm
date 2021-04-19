#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

using namespace std;

int sizes[200002];
int link[200002];

int finds(int x)
{
    if (link[x] == x)
        return x;
    return link[x] = finds(link[x]);
}

void unite(int a, int b)
{
    a = finds(a);
    b = finds(b);

    if (a != b)
    {
        if (sizes[a] < sizes[b])
            swap(a, b);
        sizes[a] += sizes[b];
        link[b] = a;
    }
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, F, p1, p2;
    cin >> t;

    string in1, in2;

    while (t--)
    {
        cin >> F;

        // �ʱ�ȭ�ϱ�
        for (int i = 0; i < 200002; i++)
        {
            sizes[i] = 1;
            link[i] = i;
        }
        map<string, int> map;
        int nodeNum = 1;

        while (F--)
        {
            // union
            cin >> in1 >> in2;

            // map �� in1�� ������ ���, �� map�� ��� ��ȣ�� ����
            if (map.count(in1) == 0)
                map[in1] = nodeNum++;
            if (map.count(in2) == 0)
                map[in2] = nodeNum++;

            unite(map[in1], map[in2]);

            p1 = finds(map[in1]);
            p2 = finds(map[in2]);

            cout << max(sizes[p1], sizes[p2]) << '\n';
        }
    }
    return 0;
}