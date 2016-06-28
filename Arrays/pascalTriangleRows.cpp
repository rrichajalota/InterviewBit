/*  Pascal Triangle Rows
    Given numRows, generate the first numRows of Pascal’s triangle.
    Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.
    Example:
    Given numRows = 5,
    Return

    [
         [1],
         [1,1],
         [1,2,1],
         [1,3,3,1],
         [1,4,6,4,1]
    ]
*/

vector<vector<int> > Solution::generate(int A) {
    vector<vector<int>> pattern;
    vector<int> row;
    if(A==0)
        return pattern;
    
    row.push_back(1);
    pattern.push_back(row);
    
    if(A==1)
        return pattern;
        
    row.push_back(1);
    pattern.push_back(row);
    
    if(A==2)
        return pattern;
    
    for(int r=2; r < A; r++){
        vector<int> col;
        col.push_back(1);
        for(int c=1; c < r; c++){
            col.push_back(pattern[r-1][c-1]+ pattern[r-1][c]);
        }
        col.push_back(1);
        pattern.push_back(col);
    }
    return pattern;
}