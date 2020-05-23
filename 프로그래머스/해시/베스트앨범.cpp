#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return a.second < b.second;
	else return a.first > b.first;
}

bool cmp2(pair<int, string> a, pair<int, string> b) {
	return a.first > b.first;
}

int main() {
	vector<string> genres = { "classic", "pop", "classic", "classic", "pop"};
	vector<int> plays = { 500, 600, 500, 800, 2500 };

	vector<int> answer;

	map<string, vector<pair<int,int>>> v;                 // 각 장르마다의 재생횟수

	set<string> s;                                        // 장르(중복x)
	set<string>::iterator itr;

	vector<pair<int, string>> temp;                      // 각 장르의 총 재생 횟수를 담은 vector -> 총 횟수 기준으로 정렬하기 위해 만듬
	map<string, int> m;                                  // 장르의 총 횟수

	for (int i = 0; i < genres.size(); i++) {
		v[genres[i]].push_back({ plays[i], i });
		s.insert(genres[i]);
		m[genres[i]] += plays[i];
	}

	for (itr = s.begin(); itr != s.end(); ++itr) 
		temp.push_back({ m[*itr],*itr});
	sort(temp.begin(), temp.end(), cmp2);

	for (int i = 0; i < temp.size(); i++) {
		sort(v[temp[i].second].begin(), v[temp[i].second].end(), cmp);
		for (int j = 0; j < v[temp[i].second].size(); j++) {
			answer.push_back(v[temp[i].second][j].second);
			if (j == 1) break;
		}
	}
	for (int i = 0; i < answer.size(); i++) 
		printf("%d\n", answer[i]);
	return 0;
}