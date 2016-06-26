/*  First missing positive integer
    Given an unsorted integer array, find the first missing positive integer.
    Example:
    Given [1,2,0] return 3,
    [3,4,-1,1] return 2,
    [-8, -7, -6] returns 1

    Your algorithm should run in O(n) time and use constant space.
*/


int Solution::firstMissingPositive(vector<int> &A) {
    
    int n = A.size(), i=0;
        while(i < n) {
            if (A[i] > 0 && A[i] <= n) {
                int pos = A[i] - 1;
                if (A[pos] != A[i]) {
                    swap(A[pos], A[i]);
                }
                else ++i;
            }
            else ++i;
        }
        for (int i = 0; i < n; i++) {
            if (A[i] != i + 1) 
                return i + 1;
        }
    return n + 1;
}
