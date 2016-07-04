/*  SORT BY COLOR

    Given an array with n objects colored red, white or blue, 
    sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
    Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

    Note: Using library sort function is not allowed.

    Example :

    Input : [0 1 2 0 1 2]
    Modify array so that it becomes : [0 0 1 1 2 2]
*/

void Solution::sortColors(vector<int> &A) {
    int red=0, blue= A.size()-1;      //maintain 2 pointers for positioning red and blue, 
    for(int k=0; k< A.size(); k++){  // white will be positioned automatically
        
        if(A[k]==0 && i < k){       //if i=k then no need to swap 
            swap(A[k], A[i]);       //swap the values at k and i so that i now holds 0
            ++i; --k;               //now increment i so that next 0 value is placed at this position. 
        }                           //decrement k so that the swapped value is checked again
        
        else if(A[k]==2 && j > k){    // j > k checked so that when k reaches towards the end of the array
                                      // it doesn't swap the already set 2.
            while(A[j]==2 && j > k){  //if the value at the end = 2 decrement j so that A[j] != 2
                --j;
            }
            swap(A[k], A[j]);
            --j; --k;
        }
    }
}
