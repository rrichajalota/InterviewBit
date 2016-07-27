/*  Rotated Array
    
    Suppose a sorted array A is rotated at some pivot unknown to you beforehand.
    (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

    Find the minimum element.
    The array will not contain duplicates.
*/

int Solution::findMin(const vector<int> &A) {
    int low=0, high= int(A.size()-1);
    int len = A.size();
    while (low <= high) {
        if (A[low] <= A[high]) return A[low]; // Case 1
        int mid = (low + high) / 2;
        int next = (mid + 1) % len, prev = (mid + len - 1) % len;
        if (A[mid] <= A[next] && A[mid] <= A[prev]) // Case 2
            return A[mid];
        else if (A[mid] <= A[high]) high = mid + 1; // Case 3
        else if (A[mid] >= A[low]) low = mid + 1; // Case 4
    }
    return -1;
}
