/*  PRIME SUM
    Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.
    NOTE A solution will always exist. read Goldbach’s conjecture
    Example:
    Input : 4
    Output: 2 + 2 = 4
    If there are more than one solutions possible, return the lexicographically smaller solution.
    If [a, b] is one solution with a <= b,
    and [c,d] is another solution with c <= d, then
    [a, b] < [c, d] 
    If a < c OR a==c AND b < d. 
*/
/*  Solution Approach
    First, find the prime numbers till number A and store them in a hash table. Now, loop through the table to find the two
    numbers.
*/

int min(int a, int b){
    return a < b ? a : b;
}


vector<int> Solution::primesum(int A) {
    vector<bool> prime(A,true);
    
    prime[0]=prime[1]=false;
    
    for(int i=2; i < A; i++){
        
        if(prime[i]){
            int j= i;
            while(j < A && j+i < A){
                prime[j+i]= false;
                j= j+i;
            }
        }
    }
    
    int first=0, second=0;
    for (int p=2; p < A; p++){
        if(prime[p]==true && prime[A-p]==true){
            if(!first && !second){
                first= p;
                second= A-p;
            }
        }
    }
    vector<int> result;
    result.push_back(first);
    result.push_back(second);
    return result;
}



