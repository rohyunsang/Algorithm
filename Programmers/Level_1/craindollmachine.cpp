#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {

	stack<int> bucket;
	bucket.push(-1);
	int answer = 0;

	for (int i = 0; i < moves.size(); i++) {
		int check = moves[i] - 1;
		for (int j = 0; j < board.size(); j++) {
			if (board[j][check] != 0) {
				if (!bucket.empty() && bucket.top() == board[j][check]) {
					bucket.pop();
					answer += 2;
				}
				else
					bucket.push(board[j][check]);
				board[j][check] = 0;
				break;
			}
		}
		
	}
		
	return answer;
}