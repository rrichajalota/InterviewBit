/*  Palindrome String
    Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
    Example:

    "A man, a plan, a canal: Panama" is a palindrome.

    "race a car" is not a palindrome.

    Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/

int Solution::isPalindrome(string A) {

    int len= A.length();
    int i= 0, j= len-1;

    while (i < j){

        if(!isalnum(A[i]))
            ++i;

        if(!isalnum(A[j]))
            --j;

        else if(isalnum(A[i]) && isalnum(A[j])){

            if(tolower(A[i]) != tolower(A[j]))
                return 0;

            else ++i, --j;
        }
        
    }

    return 1;
}