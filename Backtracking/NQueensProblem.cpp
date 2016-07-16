/*  N Queens Problem
    The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
    Given an integer n, return all distinct solutions to the n-queens puzzle.
    Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

    For example,
    There exist two distinct solutions to the 4-queens puzzle:

    [
     [".Q..",  // Solution 1
      "...Q",
      "Q...",
      "..Q."],

     ["..Q.",  // Solution 2
      "Q...",
      "...Q",
      ".Q.."]
    ]
*/

/*  Solution Approach
    We will use a single vector to denote the positions of non-attacking queens in an AxA matrix.
    board[i]= j means in the ith row and jth column, a queen is placed. For A= 4, if board= {2,4,1,3} this means 
    queens are placed in row 0, 2nd column, in row 1, 4th column, in row 2, 1st column and in row 3, 3rd column.
    Two queens will be in the non-attacking positions if they are not in the same column, not in the same row and not in the 
    same diagonals. We place queens row-wise. So, A[i] != A[row] (not in the same column) and A[row]- A[i] != row- i 
    (not in the same diagonal).
*/

void printres(vector<int> &board,int A, vector<vector<string>> &result);
bool isQueenSafe(vector<int> &board, int r);
void nQueenBacktrack(vector<int> &board, int cur, int A, vector<vector<string>> &result);

vector<vector<string> > Solution::solveNQueens(int A) {

   vector<vector<string>> result;
   vector<int> board(A);
   nQueenBacktrack(board,0,A,result);
   return result;

}

void printres(vector<int> &board,int A, vector<vector<string>> &result){

        vector<string> row;

        for(int i=0; i < A ; i++){
            string str(A,'.');
            str[board[i]]='Q';
            row.push_back(str);
        }

        result.push_back(row);
}

bool isQueenSafe(vector<int> &board, int r){

    for (int i=0; i < r; i++){
            if ( (board[i]==board[r]) || ( abs(board[i]-board[r])==(r-i) ) ){   // if another queen is in the same column or diagonal
                return false;
            }
        }

    return true;
}

void nQueenBacktrack(vector<int> &board, int cur, int A, vector<vector<string>> &result){
    if( cur== A ){
        printres(board, A, result);
        return;
    }
    for(int i=0; i < A; i++){
        board[cur]= i;
        
        if(isQueenSafe(board, cur))
            nQueenBacktrack(board, cur+1, A, result);
    }
}
