/*  REARRANGE ARRAY
    Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.
    Example:
    Input : [1, 0]
    Return : [0, 1]

     Let's say N = size of the array. Then, following holds true :
    * All elements in the array are in the range [0, N-1]
    * (N * N) does not overflow for a signed integer 
*/

// we store both the old value and current value at one index. 

void Solution::arrange(vector<int> &A) {
    int n= A.size();
    for(int i=0; i < n ; i++){

        if(A[i] < i){
            if (A[A[i]] < n)
                A[i]= A[i]*n;
            else
               A[i]= A[A[i]]/n + A[i]*n;
        }

        else
            A[i]= A[i]*n + A[A[i]];
            
    }
    for(int i=0; i < n; i++){
        if (A[i] >= n){
            A[i]= A[i] % n;
        }
    }
}
