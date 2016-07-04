/*  CONTAINER WITH MOST WATER
    Given n non-negative integers a1, a2, ..., an,
    where each represents a point at coordinate (i, ai).
    'n' vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).

    Find two lines, which together with x-axis forms a container, such that the container contains the most water.

    Your program should return an integer which corresponds to the maximum area of water that can be contained ( Yes, we know maximum area instead of maximum volume sounds weird. But this is 2D plane we are working with for simplicity ).

     Note: You may not slant the container. 
    Example :

    Input : [1, 5, 4, 3]
    Output : 6

    Explanation : 5 and 3 are distance 2 apart. So size of the base = 2. Height of container = min(5, 3) = 3. 
    So total area = 3 * 2 = 6
*/

int Solution::maxArea(vector<int> &A) {
   int maxarea=0, high= A.size()-1, low=0;

   while(low < high){

       int base= high-low;                        // Initially, maximum possible base is (N-1)-(0) and
       int area= base* min(A[low], A[high]);      // max possible area = (N-1) * min(A[0], A[N-1]) where min(A[0], A[N-1]) is height
       maxarea= max(area, maxarea);

       if(A[low] < A[high])                       // A better area exists only if height > min(A[0], A[N-1]); so if A[0] < A[N-1] 
            ++low;                                // increment 0 to 1, and repeat the procedure again
       else --high;                               // else, decrement N-1 to N-2 and repeat the procedure again.
        
   }
   return maxarea;
}
