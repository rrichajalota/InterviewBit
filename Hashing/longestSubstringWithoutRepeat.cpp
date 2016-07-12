/*  Longest Substring without Repeat
    
    Given a string, 
    find the length of the longest substring without repeating characters.
    Example:
    The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
    For "bbbbb" the longest substring is "b", with the length of 1.
*/

int Solution::lengthOfLongestSubstring(string A) {
    int maxcount=0;
    int i=0;
    
    while( i < A.length() ){
        
        int count=0; 
        map<char, int> character;     //stores a character and it's index

        while( i < A.length() && character.count(A[i])== 0){
            character[A[i]]= i;
            ++count, ++i;
        }
        
        maxcount= max(count, maxcount);
        
        if(i == A.length())
            break;
            
        i= character[A[i]]+1;
        
    }
    return maxcount;
}
