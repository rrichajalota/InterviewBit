/*
    Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

    For example:

    Given the array [-2,1,-3,4,-1,2,1,-5,4],

    the contiguous subarray [4,-1,2,1] has the largest sum = 6.

    For this problem, return the maximum sum.
*/

// Brute force solution. time complexity- O(n^2).

int Solution::maxSubArray(const vector<int> &A) {

    int maxsum= A[0], startIndex=0, minIndex=0, maxIndex;

    for (int i= 0; i< A.size(); i++){
        startIndex= i; int j= i, sum=0;
        
        while(j < A.size()){
            sum += A[j];
            if(sum >= maxsum){
                minIndex= startIndex;
                maxIndex= j;
                maxsum= sum;
            }
            ++j;
        }
    }
    return maxsum;
}
