/*  Substring Concatenation
    You are given a string, S, and a list of words, L, that are all of the same length.

    Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

    Example :

    S: "barfoothefoobarman"
    L: ["foo", "bar"]
    You should return the indices: [0,9].
    (order does not matter).
*/

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
   // string s= B[0];
    int len = B[0].size(); //found the length of the strings in B
    vector<int> ans;
    
    if(A.size()==0 || B.size()==0){
        return ans;
    }
    
    map<string, int> present;
    
    int word=0;
    for(int i=0; i < B.size(); i++){
        present[B[i]] += 1;
        ++word;
    }
    if (word*len > A.length())
        return ans;
    
    for(int i= 0; i < A.length()-(word*len)+1; ++i){
        
        int start= i;
        map<string, int> temp;
        int count=0, j=i;
        
        while(j < A.length() && count < word){   
            string str= A.substr(j,len);
            temp[str]+= 1;
            ++count, j= j+len;
        }
        
        if(temp==present){
            ans.push_back(start);
        }
        
    }
    return ans;
}
