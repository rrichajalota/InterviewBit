/* MAX NON-NEGATIVE SUB- ARRAY
    Find out the maximum sub-array of non negative numbers from an array.
    The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

    Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

    Example:

    A : [1, 2, 5, -7, 2, 3]
    The two sub-arrays are [1, 2, 5] [2, 3].
    The answer is [1, 2, 5] as its sum is larger than [2, 3]
    NOTE: If there is a tie, then compare with segment's length and return segment which has maximum length
    NOTE 2: If there is still a tie, then return the segment with minimum starting index
*/

vector<int> Solution::maxset(vector<int> &A) {

    long long maxsum= -1; int minIndex= 0, i=0;
    vector<int> maxsubarray;
    while(i< A.size()){

        vector<int> subarray;
        long long subsum=0; int startIndex=i;

        while(i< A.size() && A[i]>=0){
            subarray.push_back(A[i]);
            subsum += A[i];
            ++i;
        }
        if(subsum > maxsum){
            maxsubarray= subarray;
            maxsum= subsum;
            minIndex=startIndex;
        }
        else if(subsum == maxsum && subarray.size() > maxsubarray.size()){
            maxsubarray= subarray;
            minIndex=startIndex;
        }
        else if(subsum==maxsum && subarray.size()== maxsubarray.size() && startIndex < minIndex){
            minIndex=startIndex;
        }
        ++i;
        
    }
    return maxsubarray;
}
