/*  NEXT PERMUTATION
    Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers.
    If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.
    The replacement must be in-place, do not allocate extra memory.
    Examples:

    1,2,3 → 1,3,2

    3,2,1 → 1,2,3

    1,1,5 → 1,5,1

    20, 50, 113 → 20, 113, 50
*/

void Solution::nextPermutation(vector<int> &A) {
    
    int k= -1;

    for (int i=A.size()-1; i >= 0; --i){    // if input- (9, 3, 5, 4, 0), first find the position where 3 exists. store it in k.
        if(A[i]>A[i-1]){     
            k= i-1;             
            break;
        }

    }
    if(k != -1){                        // if next permutation exists, 

        int i= A.size()-1;
        while(A[i]<A[k]){               //find the number which is just greater than 3. i.e 4 
            --i;
        }

        swap(A[i], A[k]);              // swap with 4. The array now is (9, 4, 5, 3, 0). 
    }

    int i= k+1;                        // now just reverse the numbers from the (k+1)th position to get the next permutation 
    int j= A.size()-1;

    while(i<j){                         // output- (9, 4, 0, 3, 5) 
        swap(A[i++], A[j--]);
    }

}
