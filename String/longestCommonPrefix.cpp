/*  LONGEST COMMON PREFIX

    Write a function to find the longest common prefix string amongst an array of strings.
    Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.
    As an example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".
    Given the array of strings, you need to find the longest S which is the prefix of ALL the strings in the array.

    Example:
    Given the array as:
    [

      "abcdefgh",

      "aefghijk",

      "abcefgh"
    ]
    The answer would be “a”.
*/

string Solution::longestCommonPrefix(vector<string> &A) {
    
    int numOfstrings= A.size();
    string substr= A[0];
    
    for( int i = 1 ; i < numOfstrings; i++ ){
        
        int j=0, k=0;
        string str= A[i], newstr= "";
        
        while(j < substr.length() && k < str.length() && substr[j] == str[k]){
            newstr += substr[j];
            ++j, ++k;
        }
        
        substr= newstr;
    }
    
    return substr;
}
