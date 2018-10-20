#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pos {
    int x, y;
};

class Solution {
public:
    bool judge(Pos& a, Pos& b) {
        if(a.x == b.x || a.y == b.y || (a.x/3*3 == b.x/3*3 && a.y/3*3 == b.y/3*3))
            return false;
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<Pos> > v(10);
        for(int x = 0; x < 9; ++x) {
            for(int y = 0; y < 9; ++y) {
                if(board[x][y] == '.') continue;
                int idx = board[x][y] - '0';
                Pos pos = {x, y};
                if(!v[idx].empty()) {
                    for(auto p : v[idx]) {
                        if(!judge(p, pos))
                            return false;
                    }
                }
                v[idx].push_back(pos);
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char> > board = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}};
    cout << boolalpha << Solution().isValidSudoku(board);
    return 0;
}