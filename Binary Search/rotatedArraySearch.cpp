/* ROTATED ARRAY SEARCH
    
    Suppose a sorted array is rotated at some pivot unknown to you beforehand.
    (i.e., 0 1 2 4 5 6 7  might become 4 5 6 7 0 1 2 ).
    You are given a target value to search. If found in the array, return its index, otherwise return -1.
    You may assume no duplicate exists in the array.
    Input : [4 5 6 7 0 1 2] and target = 4
    Output : 0
    NOTE : Think about the case when there are duplicates. Does your current solution work? How does the time complexity change?*
*/

// if duplicates exist, we would have to do linear search. time complexity will change to O(n).

int Solution::search(const vector<int> &A, int B) {
    bool duplicate= false;
    int low= 0, high= A.size()-1;
    int pivot= -1, min= A[0];
    
    // search for the pivot first
    while(low < high){
        int mid= (low+high)/2;
        
        if(A[mid] < min){
            min= A[mid];
            pivot= mid;
        }
        if (A[mid] == A[high] && mid != high){
            duplicate= true;
            break;
        }
        else if (A[mid] < A[high]){
            high= mid;
        }
        else low= mid+1;
    }
    // if duplicates exist, linear search!
    if (duplicate){
        for(int i=0; i < A.size(); i++){
            if (A[i]==B)
                return i;
        }
        return -1;
    }
    else{ // else do binary search
        if(A[pivot]==B)
            return pivot;
            
        else if(A[pivot+1]<= B && A[A.size()-1] >= B)
            low= pivot+1, high= A.size()-1;
            
        else low= 0, high= pivot-1;
        while( low <= high){
            int mid= (low+high)/2;
            if (A[mid]== B)
                return mid;
            else if(A[mid] < B)
                low= mid+1;
            else high= mid-1;
        }
    }
    return -1;
}
