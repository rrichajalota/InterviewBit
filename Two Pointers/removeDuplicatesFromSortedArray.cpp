/*	Remove Duplicates from Sorted Array

	Given a sorted array, remove the duplicates in place such that each element appears only once and return the new length.
	Note that even though we want you to return the new length, make sure to change the original array as well in place

	Do not allocate extra space for another array, you must do this in place with constant memory.

	Example: 
	Given input array A = [1,1,2],
	Your function should return length = 2, and A is now [1,2]. 
*/

int Solution::removeDuplicates(vector<int> &A) {
    int writeIndex=1;
    for(int i=1; i < A.size(); i++){
        if(A[i] != A[i-1]){
            A[writeIndex++]= A[i];
        }
    }
    A.resize(writeIndex);
    return writeIndex;
}
