/*  3 Sum
    Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
    Return the sum of the three integers. 
    You may assume that each input would have exactly one solution.

    Example: 
    given array S = {-1 2 1 -4}, 
    and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)
*/

int Solution::threeSumClosest(vector<int> &A, int B) {
    
    int minsum= 100000000, sum=0;
    sort(A.begin(), A.end());
    
    for(int i=0; i < A.size(); i++){
        
        int j= i+1, k= A.size()-1;
        
        while(j < k){
            
            sum = A[i] + A[j] + A[k];
            
            if(abs(B-sum) < abs(B-minsum))
                minsum= sum;
                
            if(sum < B)
                ++j;
                
            else --k;
        }
    }
    return minsum;
}
