#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;


int main() {

	vector<vector<int>> board = { {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} };
	vector<int> moves = {1,5,3,5,1,2,1,4};

	int answer = 0;

	int movesSize = moves.size();

	stack<int> bascket;

	for (int i = 0; i < movesSize; i++) {
		for (int j = 0; j < board.size(); j++) {
			if (board[j][moves[i] - 1] != 0) {
				if (!bascket.empty() && bascket.top() == board[j][moves[i] - 1]) {
					bascket.pop();
					answer += 2;
				}
				else{
					bascket.push(board[j][moves[i] - 1]);
				}
				board[j][moves[i]-1] = 0;
				break;
			}
		}
	}
	printf("%d\n", answer);

	return 0;
}