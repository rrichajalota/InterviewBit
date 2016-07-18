/*  Combination Sum-II

    Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
    Each number in C may only be used once in the combination.
    Note:
    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combinations.
    Example :
    Given candidate set 10,1,2,7,6,1,5 and target 8,
    A solution set is:
    [1, 7]
    [1, 2, 5]
    [2, 6]
    [1, 1, 6]
*/
void combsum(vector<int> &A, int B, int index, int &sum, vector<int> &set,vector<vector<int>> &ans);

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<vector<int>> ans;
    vector<int> set;
    sort(A.begin(), A.end());
    int sum= 0;
    combsum(A, B, 0, sum, set, ans);
    return ans;
}

void combsum(vector<int> &A, int B, int index, int &sum, vector<int> &set, vector<vector<int>> &ans){
    if(sum== B){
        ans.push_back(set);
        return;
    }
    if(sum > B)
        return;

    if(index== A.size()){
        return;
    }
    
    int endindex;  

    for(endindex=index+1; endindex < A.size() && A[endindex]==A[endindex-1]; endindex++);

    int count = endindex-index;

    for(int i= 0 ; i <= count; i++){

        for(int j= 0; j < i; j++)
            set.push_back(A[index]);

        sum += i *A[index];

        combsum(A,B,endindex, sum, set, ans);

        sum -= i*A[index];
        
        for(int j= 0; j < i; j++)
            set.pop_back();
        
    } 
}