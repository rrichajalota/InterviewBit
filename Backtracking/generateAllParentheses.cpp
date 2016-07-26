/*  Generate all parentheses

    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.
    For example, given n = 3, a solution set is:
    "((()))", "(()())", "(())()", "()(())", "()()()"
    Make sure the returned list of strings are sorted.
*/

void genParen(int A, int open, int close, vector<string> &ans, string set);

vector<string> Solution::generateParenthesis(int A) {
    vector<string> ans;
    if(A==0)
        return ans;
    genParen(A,0,0,ans,"");
    return ans;
}

void genParen(int A, int open, int close, vector<string> &ans, string set){
    
    if(open==A && close==A){
        ans.push_back(set);
        return;
    }
        
    if(open < A)
        genParen(A,open+1,close,ans, set+"(");
    
    if(close < open)
        genParen(A,open,close+1,ans, set+")");
}

