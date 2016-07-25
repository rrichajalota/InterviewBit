/*  Anti-Diagonals
    Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.
    Example:
    Input:  

    1 2 3
    4 5 6
    7 8 9

    Return the following :
    [ 
      [1],
      [2, 4],
      [3, 5, 7],
      [6, 8],
      [9]
    ]
*/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    vector<vector<int>> ans;
    int sum=0;
    int i=0,j=0;
    
    while(sum <= 2*(A.size()-1)){
        vector<int> row;
    
        while(sum == i+j && i < A.size() && j >=0 ){
            row.push_back(A[i][j]);
            ++i, --j;
        }
        
        ++sum;
        ans.push_back(row);
        i=0, j= sum;
        
        while(j > A.size()-1){
            --j, ++i;
        }
    }
    return ans;
}
