/* Reverse Bits
    Reverse bits of an 32 bit unsigned integer

    Example 1:

    x = 0,

              00000000000000000000000000000000  
    =>        00000000000000000000000000000000
    return 0

    Example 2:

    x = 3,

              00000000000000000000000000000011 
    =>        11000000000000000000000000000000
    return 3221225472
*/
//O(n) solution. swaps whenever the bits are different 

unsigned int Solution::reverse(unsigned int A) {
    int n= sizeof(A)* 8; //bits
    int i=0, j= n-1;

    while(i < j){
        int rightbit= (A>>i) & 1;
        int leftbit= (A>>j) & 1;
        if(rightbit != leftbit){
            A ^= ((1u<<j) | (1u<<i));
        }
        i++, j--;
    }

    return A;
}
