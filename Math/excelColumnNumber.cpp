/*	Excel Column Number
	Given a column title as appears in an Excel sheet, return its corresponding column number.
	Example:
	    A -> 1
	    B -> 2
	    C -> 3
	    ...
	    Z -> 26
	    AA -> 27
	    AB -> 28 
*/

int Solution::titleToNumber(string A) {
    
    int sum=0;
    for (int i=0; i< A.length(); i++){
        int letterno= A[i]- 'A' + 1;
        sum = sum*26 + letterno;
    }
    return sum;
}
