/* Repeat and Missing Number Array
    
    You are given a read only array of n integers from 1 to n.
    Each integer appears exactly once except A which appears twice and B which is missing.
    Return A and B.
    Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
    Note that in your output A should precede B.
    Example:
    Input:[3 1 2 5 3] 
    Output:[3, 4] 
    A = 3, B = 4
*/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    
    int n = A.size();
    
    long long sum= 0;
    long long sumsquare= 0;
    //long long sum=0, sumsquare=0;
    long long repeat=0;
    long long missing= 0;
    
    vector<int> result;
    
    for(int i=0; i< n; i++){
        sum += (i+1);
        sum -= A[i];
        sumsquare += (long long)(i+1) * (long long)(i+1);
        sumsquare -= (long long)A[i]*(long long)A[i];
    }

    repeat= ((sumsquare/sum)+ sum)/2;
    missing= (repeat - sum);
    result.push_back(missing);
    result.push_back(repeat);
    return result;
    
    
}
