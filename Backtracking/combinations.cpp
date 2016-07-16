/*  Combinations
    Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.
    Make sure the combinations are sorted.
    To elaborate,
    1. Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
    2. Entries should be sorted within themselves.
    Example :
    If n = 4 and k = 2, a solution is:

    [
      [1,2],
      [1,3],
      [1,4],
      [2,3],
      [2,4],
      [3,4],
    ]
*/

/*  Soluion Approach
    Consider the case n = 5 and k = 3, check for its cases and simulate the algorithm. 
*/
    
void getcombination(vector<int> &A, vector<int> &B, int index, int k, vector<vector<int>> &ans);

vector<vector<int> > Solution::combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> A, B;
    for(int i= 1; i <= n; i++)
        A.push_back(i);
    getcombination(A,B,0,k,ans);
    return ans;
}

void getcombination(vector<int> &A, vector<int> &B, int index, int k, vector<vector<int>> &ans){
    
    if(B.size()==k){
        ans.push_back(B);
        return;
    }
    for(int i= index; i < A.size(); i++){
        if(B.size()==0 && i+k-1 > A.size())
            return;
        B.push_back(A[i]);
        getcombination(A,B,i+1,k,ans);
        B.pop_back();
    }
}
