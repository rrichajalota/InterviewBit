/*  Count Element Occurence

    Given a sorted array of integers, find the number of occurrences of a given target value.
    Your algorithm’s runtime complexity must be in the order of O(log n).
    If the target is not found in the array, return 0

    Example : 
    Given [5, 7, 7, 8, 8, 10] and target value 8,
    return 2.
*/

int Solution::findCount(const vector<int> &A, int B) {
    int low= 0, high= A.size()-1, count=0, first = -1;

    while(low <= high){
        int mid = (low+ high)/ 2;
        if (A[mid] == B){
            first = mid;
            high= mid-1;
            
        }
        else if(A[mid] < B)
            low= mid+1;
        else 
            high= mid-1;
    }
    
    if (first == -1)
        return 0;
        
    int second= 0;
    high= A.size()-1;
    while(low <= high){
        int mid = (low+ high)/ 2;
        if (A[mid] == B){
            second = mid;
            low= mid+1;
            
        }
        else if(A[mid] < B)
            low= mid+1;
        else 
            high= mid-1;
    }
    
    return (second - first + 1);
}
