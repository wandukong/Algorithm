
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int parent[100001];

int get(int x){
    if(parent[x] == x) return x;
    return parent[x] = get(parent[x]);
}

void set(int a, int b){
    a = get(a), b= get(b);
    if(a>b)
    swap(a,b);
    parent[a] = b;
}

int main()
{
    for(int i = 0 ; i < N ; i++)
        parent[i] = i;
        
    return 0;
}