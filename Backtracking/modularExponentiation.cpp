/*  Modular Exponentiaion
    Implement pow(A, B) % C.

    In other words, given A, B and C, 
    find (AB)%C.

    Input : A = 2, B = 3, C = 3
    Return : 2 
    2^3 % 3 = 8 % 3 = 2
*/
/*  SOLUTION APPROACH
    35 % 3 = 2. 
    Also, (7 % 3 * 5 % 3) % 3 = 2.
*/

int Solution::Mod(int A, int B, int C) {
    
    if(B==0)
        return 1 % C;
        
    long long res= 0;
    if(B%2!=0){   //if B is odd
        res= A % C;
        res= (res * Mod(A,B-1,C)) %  C;
    }
    else{
        res= Mod(A,B/2,C);
        res= (res*res) %C;
    }
    return int((res+C) % C);
}
