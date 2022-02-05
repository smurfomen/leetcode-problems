#include <string>
#include <cassert>
#include <iostream>
#include <vector>
#include <list>
#include <sstream>
using namespace std;

/*
    The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
    Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
    Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

    Example 1:
        Input: n = 4
        Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
        Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

    Example 2:
        Input: n = 1
        Output: [["Q"]]


    Constraints:
        1 <= n <= 9
*/

struct Queen {
    int r, c;
    Queen(int row, int column)
        : r(row), c(column)
    {

    }

    string toRowString(int boardSize) const {
        stringstream ss;
        for(int i = 0; i < boardSize; ++i)
        {
            ss << (i == c ? "Q" : ".");
        }

        string s;
        ss >> s;
        return s;
    }

    bool isAttack(const Queen & o) const {
        return r == o.r || c == o.c || abs(r - o.r) == abs(c - o.c);
    }
};

class Solution {
public:
    using Board = list<Queen>;

    list<Board> generateBoardVariants(int boardSize, Board board = Board{})
    {
        if(board.size() == boardSize)
            return list<list<Queen>> {{board}};

        // current row
        int row = board.size();

        // 0..4 candidate queen for row, which not attacked exists queens
        list<Board> result;

        // generate available list of queens
        for(int column = 0; column < boardSize; ++column) {
            Queen queen(row, column);
            bool attacked = false;
            for(auto existQueen : board)
            {
                attacked = existQueen.isAttack(queen);
                if(attacked)
                    break;
            }

            // if not attacked - accept candidate queen
            if(!attacked) {
                // go forward recurse for exist queens with finded not attacked candidate
                Board boardWithCandidate = board;
                boardWithCandidate.push_back(queen);

                auto boards = generateBoardVariants(boardSize, boardWithCandidate);

                for(auto variant : boards)
                {
                    if(variant.size() == boardSize)
                        result.push_back(variant);
                }
            }
        }

        return result;
    }

    vector<vector<string>> solveNQueens(int n) {
        auto boards = generateBoardVariants(n);

        vector<vector<string>> result;
        for(Board board : boards)
        {
            vector<string> vec;
            for(auto queen : board)
            {
                vec.push_back(queen.toRowString(n));
            }
            result.push_back(vec);
        }

        return result;
    }
};

int main(int argc, char * argv[]) {
    Solution sol;



    auto print = [](const vector<vector<string>> & boards) {
        for(auto board : boards)
        {
            cout << "{ ";
            for(int row = 0; row < board.size(); ++row) {
                cout << board[row];
                if(row < board.size() - 1)
                    cout << ", ";
            }

            cout << " }" << endl;
        }
    };

    assert((sol.solveNQueens(4) == vector<vector<string>> {{ ".Q..", "...Q", "Q...", "..Q." }, { "..Q.", "Q...", "...Q", ".Q.." }}));
    assert((sol.solveNQueens(1) == vector<vector<string>> {{"Q"}} ));


    cout << "tests is passed!" << endl;

    return 0;
}
