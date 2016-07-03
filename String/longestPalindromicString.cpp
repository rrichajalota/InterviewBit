/*  LONGEST PALINDROMIC STRING
    Given a string S, find the longest palindromic substring in S.
    Substring of string S:
    S[i...j] where 0 <= i <= j < len(S)
    Palindrome string:
    A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.
    Incase of conflict, return the substring which occurs first ( with the least starting index ).

    Example :

    Input : "aaaabaaa"
    Output : "aaabaaa"
*/

string Solution::longestPalindrome(string A) {
    
    string palin=A.substr(0,1), substr;
    int palinlen= 1, sublen=0;
    //check for odd centers (aba)
    for(int i=1; i < A.length(); i++){
        int j = i+1;
        int k = i-1;
        while( A[k]==A[j] && k >= 0 && j <= A.length()-1){ 
            if(j - k + 1 > palinlen){
                palinlen= j-k+1;
                palin = A.substr(k,palinlen);
            }
            --k, ++j;
        }
    }
    //check for even centers (abba)
    for(int i=1; i < A.length(); i++){
        int j = i;
        int k=i-1;
        while(A[k]==A[j] && k >= 0 && j <= A.length()-1){
            if(j - k + 1 > palinlen){
                palinlen= j-k+1;
                palin = A.substr(k,palinlen);
            }
            --k, ++j;
        }
    }
    return palin;
}
