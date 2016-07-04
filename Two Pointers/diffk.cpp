/*  Diffk
    Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

     Example: Input : 
        A : [1 3 5] 
        k : 4
     Output : YES as 5 - 1 = 4 
    Return 0 / 1 ( 0 for false, 1 for true ) for this problem

    Try doing this in less than linear space complexity.
*/

/*  time complexity- O(n)
    consider the examples, A: [1 3 5] k: 4 and A:[1 2 2 3 5] k:0, while solving.
*/

int Solution::diffPossible(vector<int> &A, int B) {
    int i=0, j=1;           // both the pointers start from the beginning of the array

    while(j != A.size()){

        if(A[j]- A[i]== B)  //if the diff is found
            return 1;

        if(A[j]- A[i] > B){ //if the diff is greater than B, then certainly all values at indices > j, will have a larger difference. 
            ++i;            // therefore, we increase i. 
            if(i==j) ++j;   // if i becomes equal to j, increase j. 
        }

        else                //if A[j]- A[i] < B   then there might exist an index, j' > j where the differece A[j']- A[i]== B
            ++j;            // so increase j. 
    }
    return 0;
}
