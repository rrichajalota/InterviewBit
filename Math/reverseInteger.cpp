/* Reverse Integer
  Reverse digits of an integer.

  Example1:
  x = 123,
  return 321

  Example2:
  x = -123,
  return -321

  Return 0 if the result overflows and does not fit in a 32 bit signed integer
*/
  
int Solution::reverse(int A) {
    
    if(A< INT_MIN || A > INT_MAX || ceil(log10(A)) > 32)
        return 0;
    
    bool is_neg= false;
    
    if (A < 0){
       is_neg= true;
       A= abs(A);
   }
   
   long long ans=0;
   
   while(A){
       
       ans= ans* 10 + A%10;
       A /= 10;
   }
   
   if(is_neg){
       ans = -ans;
   }
   
   if (ans< INT_MIN || ans > INT_MAX)
    return 0;
    
   return ans;
}
