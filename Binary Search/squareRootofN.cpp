/*  Square root of Integer
    Implement int sqrt(int x).
    Compute and return the square root of x.
    If x is not a perfect square, return floor(sqrt(x))

    Example :
    Input : 11
    Output : 3
    DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY
*/

int Solution::sqrt(int A) {
    
    if (A==0)
        return A;
        
    int low=1, high= A/2; long sqroot=1;
    
    while(low <= high){
        
        long long int mid = (low+high)/2;
        
        if(mid* mid == A)
            return mid;
            
        else if (mid* mid < (long long int) A){
            sqroot= mid;
            low= mid+1;
        }
        
        else high= mid-1;
    }
    
    return sqroot;
}
