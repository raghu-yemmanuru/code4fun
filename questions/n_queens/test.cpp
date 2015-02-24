#include <vector>
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;
int total = 0;

void printBoard(vector<int> &board) {
    cout << ++total << "." << endl;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[i] == j) {
                cout << " Q";
            } else {
                cout << " _";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool conflict(vector<int> &board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col) {
            return true;
        }
        if(abs(row-i) == abs(col-board[i])) {
            return true;
        }
    }
    return false;
}

void queens(vector<int> &board, int pos) {
    if (pos == board.size()) {
        printBoard(board);
        return;
    }

    for (int i = 0; i < board.size(); i++) {
        if (!conflict(board,pos,i)) {
            board[pos] = i;
            queens(board,pos+1);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> board(n,0);
    queens(board,0);
}
