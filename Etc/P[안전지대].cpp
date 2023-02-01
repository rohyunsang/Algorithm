#include <string>
#include <vector>

using namespace std;


void ChangeBoard(int x, int y, vector<vector<int>>& board) {
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i < 0 || j < 0 || i >= board.size() || j >= board.size())
                continue;
            else if (board[i][j] == 0)
                board[i][j] = 2;
        }
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[i][j] == 1)
                ChangeBoard(i, j, board);
        }
    }

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[i][j] == 0)
                answer++;
        }
    }



    return answer;
}