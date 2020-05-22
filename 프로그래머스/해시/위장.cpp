#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;


int main() {
	vector<vector<string>> clothes = { {"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"} };

	set<string> kind;
	set<string>::iterator iter;
	map<string, int> item;

	int answer = 1;

	for (int i = 0; i < clothes.size(); i++) {
		item[clothes[i][1]] += 1;
		kind.insert(clothes[i][1]);
	}
	if (kind.size() > 1) {
		for (iter = kind.begin(); iter != kind.end(); ++iter) 
			answer *= (item[*iter] + 1);
		answer -= 1;
	}else answer = clothes.size();
	
	printf("%d\n", answer);

	return 0;
}