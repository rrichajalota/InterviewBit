/*  IMPLEMENT POWER FUNCTION

    Implement pow(x, n) % d.
    In other words, given x, n and d,
    find (xn % d)
    Note that remainders on division cannot be negative. 
    In other words, make sure the answer you return is non negative.

    Input : x = 2, n = 3, d = 3
    Output : 2

    2^3 % 3 = 8 % 3 = 2.
*/

int Solution::pow(int x, int n, int d) {
    long long ans= 1, base = x;
    
    if (n==0){
        return int (1 % d);
    }
    
    while(n){
        if (n & 1) {                // if n is odd
            ans = (ans * base) % d;
        } 
        base = (base * base) % d;   
        n /= 2;                     // divide n by 2
    }
    if (ans < 0)                    // mod of negative integers is x = (x + p) % p.
        ans = (ans + d) % d;
    return ans;
}