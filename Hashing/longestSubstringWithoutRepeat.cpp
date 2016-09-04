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

/* Linear Time solution! 
   Keep track of the starting point of the substring. There can be two cases possible for 
   a character already present in the hash table. 
   1) it lies to the left of starting point i.e. it's not a part of our current substring.
   2) it lies to the right of starting point i.e. it's a part of our current substring. In
      this case, compare (len, maxlen) and set the starting point as the next index of 
      the previous occurence of the current character.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(s.length()==0)
            return 0;
            
        int i=0, len=0, maxlen=0, start=0;
        unordered_map<char, int> m;
        
        while(i < s.length()){

            if(m.find(s[i]) == m.end() || m[s[i]] < start){
                m[s[i]] = i;
                ++len;
            }
            else{
                maxlen = max(len, maxlen);
                start= m[s[i]] + 1;
                len = i - m[s[i]];
                m[s[i]]= i;
            }
            ++i;
        }
        maxlen= max(maxlen, len);
        return maxlen;
    }
};
