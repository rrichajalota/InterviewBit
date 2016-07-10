/*  Palindrome Partitioning
    Given a string s, partition s such that every string of the partition is a palindrome.

    Return all possible palindrome partitioning of s.

    For example, given s = "aab",
    Return

      [
        ["a","a","b"]
        ["aa","b"],
      ]
*/

void generatepartition(string A, int index, vector<string> &pal, vector<vector<string>> &res);
bool ispalin(string A, int start, int end);

vector<vector<string> > Solution::partition(string A) {
    vector<vector<string>> res;
    vector<string> pal;
    generatepartition(A, 0, pal, res);
    return res;
}

void generatepartition(string A, int index, vector<string> &pal, vector<vector<string>> &res){
    
    if(index== A.length()){
        res.push_back(pal);
        return;
    }
    for(int i=index; i< A.length(); i++ ){
        
        if(ispalin(A, index, i)){
            pal.push_back(A.substr(index, i-index+1));  //push the palindrome in the substring A[index:i]
            generatepartition(A, i+1,pal, res);         //find all palindromes in A[i+1: end]
            pal.pop_back();
        }
    }
}
bool ispalin(string A, int start, int end){
    while(start < end){
        if(A[start] != A[end])
            return false;
        ++start, --end;
    }
    return true;
}
