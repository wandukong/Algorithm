#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string T, P;
vector<int> answer;

void RabinKarp()
{
    int pSize = P.size(), tSize = T.size();
    long long textHashValue = 0, patterHashValue = 0, power = 1;
    long long m = 1e9 + 7;

    for (int i = pSize - 1; i >= 0; i--)
    {
        textHashValue = (textHashValue + (T[i] * power) % m) % m;
        patterHashValue = (patterHashValue + (P[i] * power) % m) % m;
        if (i != 0)
            power = (power * 107) % m;
    }

    for (int i = 0; i <= tSize - pSize; i++)
    {
        if (textHashValue == patterHashValue)
            answer.push_back(i + 1);
        textHashValue = ((107 * (textHashValue - (T[i] * power) % m)) % m + T[i + pSize]) % m;
        if (textHashValue < 0)
            textHashValue += m;
    }
}

int main()
{
    getline(cin, T);
    getline(cin, P);
    if (T.size() < P.size())
    {
        printf("0");
        return 0;
    }
    RabinKarp();
    printf("%d\n", answer.size());
    for (int i = 0; i < answer.size(); i++)
        printf("%d ", answer[i]);
    return 0;
}