/*	Trailing Zeros in Factorial
	Given an integer n, return the number of trailing zeroes in n!.

	Note: Your solution should be in logarithmic time complexity.

	Example :

	n = 5
	n! = 120 
	Number of trailing zeros = 1
	So, return 1
*/
/*	SOLUTION APPROACH
	find the multiples of 5, 5x5, 5x5x5.. so on in the number.
*/

int Solution::trailingZeroes(int A) {
    int divisor= 5, quot= A/divisor;
    int result= quot;
    while(quot){
        divisor *= 5;
        quot= A/divisor;
        result += quot;
    }
    return result;
}
