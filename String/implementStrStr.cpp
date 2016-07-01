/*  Implement strStr().

    strstr - locate a substring ( needle ) in a string ( haystack ). 
    Try not to use standard library string functions for this question.
    Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

    NOTE: Good clarification questions:

    What should be the return value if the needle is empty?
    What if both haystack and needle are empty?
    For the purpose of this problem, assume that the return value should be -1 in both cases. 
*/

// Time complexity- O(m*n)

int Solution::strStr(const string &haystack, const string &needle) {
    int j=0;

   if (needle[0] == '\0' || haystack[0] == '\0')
        return -1;

    for(int i=0; haystack[i] != '\0'; ++i){
        bool matched= true;

        for(j=0; needle[j]!= '\0'; ++j){
            
            if (haystack[i+j]== '\0')   //if the remaining haystack length is less than needle length
                return -1;
                
            if (haystack[i+j]!=needle[j]){  
                matched= false;
                break;
            }
        }
        
        if(matched)                     
            return i;
    }
    return -1;                  // no match found
}
