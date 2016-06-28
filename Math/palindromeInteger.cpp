/*  Palindrome Integer
    Determine whether an integer is a palindrome. Do this without extra space.
    A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
    Negative numbers are not palindromic.
*/

bool Solution::isPalindrome(int A) {
    
    if( A < 0 )
        return false;
        
    int len= int(log10(A))+1;
    int divider= int(pow(10,len-1));
    
    while(divider>=1){
        
        int msd = A/divider;
        int lsd = A%10;
        
        if(msd!=lsd){
            return false;
        }
        
        A= A%divider;
        A= A/10;
        divider /= 100;
        
    }
    return true;
    
}
