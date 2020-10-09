#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

vector<string> gems{"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
map<string, int> cart;

int main()
{
    vector<int> answer;

    int ans1 = 0, ans2 = 9999999;
    int allSize = gems.size();

    vector<string> treasure = gems;

    sort(treasure.begin(), treasure.end());
    treasure.erase(unique(treasure.begin(), treasure.end()), treasure.end()); // treasure 벡터는 중복되지 않은 보물

    int allCnt = treasure.size(); // 모든 보물 종류의 갯수
    vector<string> curTreasure;   // 현재 갖고있는 보물의 종류

    int start = -1, end = -1;

    while (start <= end)
    {
        if (allCnt == curTreasure.size())
        {
            start++;
            cart[gems[start]]--;
            if (!cart[gems[start]])
                curTreasure.erase(remove(curTreasure.begin(), curTreasure.end(), gems[start]), curTreasure.end());
        }
        else if (allCnt > curTreasure.size() && end != allSize - 1)
        {
            end++;
            if (!cart[gems[end]])
                curTreasure.push_back(gems[end]);
            cart[gems[end]]++;
        }
        else
            break;

        if (allCnt == curTreasure.size())
            if (ans2 - ans1 > end - start)
                ans2 = end, ans1 = start;
    }
    answer.push_back(ans1 + 2);
    answer.push_back(ans2 + 1);
    printf("[%d, %d]\n", ans1 + 2, ans2 + 1);
    return 0;
}