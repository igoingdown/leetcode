#include <iostream>
#include <vector>

using namespace std;

bool validTicTacToe(vector<string>& board);
bool dfs(vector<string> &board, vector<string> &visit, char need);

int main() {
    vector<string> board = {"O  ", "   ", "   "};
    if (validTicTacToe(board)) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}

bool validTicTacToe(vector<string>& board) {
    vector<string> visit = {"   ", "   ", "   "};
    return dfs(board, visit, 'X');
}

bool dfs(vector<string> &board, vector<string> &visit, char need) {
    if (board == visit) return true;
    if (visit[1][1] != ' ' && (((visit[0][0] == visit[1][1] && visit[2][2] == visit[1][1])) || (visit[1][1] == visit[0][2] && visit[1][1] == visit[2][0]))) return false;
    for (int i = 0; i < 3; i++) {
        if ((visit[i][0] == visit[i][1] && visit[i][1] == visit[i][2] && visit[i][0] != ' ') || (visit[0][i] == visit[1][i] && visit[1][i] == visit[2][i] && visit[1][i] != ' ')) return false;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == need && visit[i][j] == ' ') {
                visit[i][j] = need;
                if (dfs(board, visit, need == 'X' ? 'O' : 'X')) return true;
                visit[i][j] = ' ';
            }
        }
    }
    return false;
}