/*  Permutations (method 1 using nextPermutation approach)
    Given a collection of numbers, return all possible permutations.

    Example:

    [1,2,3] will have the following permutations:

    [1,2,3]
    [1,3,2]
    [2,1,3] 
    [2,3,1] 
    [3,1,2] 
    [3,2,1]
*/

void nextpermutation(vector<int> &A, vector<vector<int>> &ans);

vector<vector<int> > Solution::permute(vector<int> &A) {

    vector<vector<int>> ans;
    sort(A.begin(), A.end());
    ans.push_back(A);

    nextpermutation(A,ans);

    return ans;
}

void nextpermutation(vector<int> &A, vector<vector<int>> &ans){
    int i;
    
    for( i= A.size()-1; i > 0; --i){
        if(A[i] > A[i-1]) 
            break;
    }
    
    if(i==0)
        return;
        
    int pos= i-1, j;
    
    for(j=A.size()-1; j > pos; --j ){
        if(A[j] > A[pos])
            break;
    }
    
    swap(A[j], A[pos]);
    sort(A.begin()+pos+1, A.end());
    ans.push_back(A);
    nextpermutation(A,ans);
}
