/*  Kth Row of pascal's triangle
    Given an index k, return the kth row of the Pascal’s triangle.
    Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.
    Example:
    Input : k = 3
    Return : [1,3,3,1]
     NOTE : k is 0 based. k = 0, corresponds to the row [1]. 
    Note:Could you optimize your algorithm to use only O(k) extra space?
*/

vector<int> Solution::getRow(int A) {
    vector<int> row;
    
    if(A < 0)
        return row;
        
    row.push_back(1);
    if(A==0)
        return row;
        
    row.push_back(1);
    if(A==1)
        return row;
        
    int i=2;
    vector<int> prev(2);
    prev= row;
    
    while( i <= A){

        for(int j=1; j<= row.size()-1; j++){
            row[j]= prev[j-1]+ prev[j];
        }

        row.push_back(1);
        prev.resize(row.size());
        prev= row;
        i++;
    }
    return row;
}
