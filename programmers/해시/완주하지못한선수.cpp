#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int main() {
	vector<string> participant = { "mislav", "stanko", "mislav", "ana" };
	vector<string> completion = { "stanko", "ana", "mislav" };
	string answer = "";
	map<string, int> p, c;

	for (int i = 0; i < completion.size(); i++)
		c[completion[i]] += 1;

	for (int i = 0; i < participant.size(); i++)
		p[participant[i]] += 1;

	for (int i = 0; i < participant.size(); i++) {
		if (c[participant[i]] != p[participant[i]]) {
			answer = participant[i];
		}
	}
	printf("%s\n", answer.c_str());

	return 0;
}