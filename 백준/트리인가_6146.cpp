#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int T, u, v;
map<int, int> indegree;
vector<int> vEdge;
set<int> edge;

int main()
{
    while (true)
    {
        scanf("%d %d", &u, &v);
        if (u < 0 && v < 0)
            break;
        if (u == 0 && v == 0)
        {
            ++T;
            set<int>::iterator it;
            int root = 0, other = 0;
            for (it = edge.begin(); it != edge.end(); it++)
            {
                if (indegree[*it] == 0)
                    root++;
                else if (indegree[*it] == 1)
                    other++;
            }
            if (edge.size() == 0)
                printf("Case %d is a tree.\n", T);
            else if (root == 1 && (int)edge.size() - 1 == other)
                printf("Case %d is a tree.\n", T);
            else
                printf("Case %d is not a tree.\n", T);
            edge.clear();
            indegree.clear();
            vEdge.clear();
        }
        else
        {
            edge.insert(v);
            edge.insert(u);
            indegree[v]++;
            vEdge.push_back(v);
        }
    }
    return 0;
}