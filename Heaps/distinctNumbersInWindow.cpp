/*  Distinct Numbers in Window

    You are given an array of N integers, A1, A2 ,…, AN and an integer K. Return the of count of distinct numbers in all windows of size K.
    Formally, return an array of size N-K+1 where i’th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,…, Ai+k-1.
    Note:
    - If K > N, return empty array.

    For example,
    A=[1, 2, 1, 3, 4, 3] and K = 3
    All windows of size K are

    [1, 2, 1]
    [2, 1, 3]
    [1, 3, 4]
    [3, 4, 3]

    So, we return an array [2, 3, 3, 2].
*/
/*  SOLUTION APPROACH
    If we have solution for window [i, i+k-1], can we quickly build solution for window [i+1, i+k]?
    If we have a data structure where we can maintain count of all keys and number of distinct keys, then we just have to 
    reduce count of key A[i] and increasing count of A[i+k]. If count of some key has been reduced to zero, we need to remove that key.
    That data structure is a hashmap! 
*/

vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> ans;
    
    if(B > A.size())
        return ans;
        
    unordered_map<int, int> m;
    int i, j;
    
    for(i= 0; i < B; i++){
        m[A[i]] += 1;
    }
    
    ans.push_back(m.size());
    
    m[A[0]] -= 1;
    if(m[A[0]]==0)
        m.erase(A[0]);
    j=1;
    
    while(i < A.size()){
        m[A[i]] += 1;
        ans.push_back(m.size());
        m[A[j]] -= 1;
        if(m[A[j]]==0)
            m.erase(A[j]);
        ++j, ++i;
    }
    
    return ans;
}
