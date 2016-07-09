/*  Subset
    Given a set of distinct integers, S, return all possible subsets.

    Note:
    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.
    Also, the subsets should be sorted in ascending ( lexicographic ) order.
    Example :

    If S = [1,2,3], a solution is:

    [
      [],
      [1],
      [1, 2],
      [1, 2, 3],
      [1, 3],
      [2],
      [2, 3],
      [3],
    ]   
*/
/*  Soluiton approach
    An element in the set can either be present in the set or absent. 
*/
void generateSubset(vector<int> &A, int start, vector<int> &set,vector<vector<int>> &ans);

vector<vector<int> > Solution::subsets(vector<int> &A) {
   sort(A.begin(), A.end());    //sort the set
   vector<int> set;
   vector<vector<int>> ans;
   generateSubset(A,0,set,ans);
   sort(ans.begin(), ans.end());    
   return ans;
}

void generateSubset(vector<int> &A, int start, vector<int> &set,vector<vector<int>> &ans){
    
    if(start== A.size()){
        ans.push_back(set);
        return;
    }
    //when start is not included in the set
    generateSubset(A,start+1,set,ans);
    // start is included in the set
    set.push_back(A[start]);
    generateSubset(A,start+1,set,ans);
    set.pop_back();
}

