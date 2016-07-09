/*  Letter Phone
    Letter PhoneBookmark Suggest Edit
    Given a digit string, return all possible letter combinations that the number could represent.
    A mapping of digit to letters (just like on the telephone buttons) is given below.
    The digit 0 maps to 0 itself.
    The digit 1 maps to 1 itself.

    Input: Digit string "23"
    Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
    Make sure the returned strings are lexicographically sorted.
*/

/*  SOLUTION APPROACH
    We start from the first digit in the string. If input is "23", then all possible mnemonics for it will either start from a, b or c. We fix the first letter of the letter string (in this case, a) for the first digit(2). now our current string looks like "a". then move to the next digit. We then place the first letter of the letter string (in this case, d) for the second digit(3). the current string now becomes "ad". we store it in the result. then pop 'd' from the back. current-> "a". place the second letter of the string in current. current->"ae". store it and repeat the same process again till all combinations have been tried for both the digits.
*/

void combinations(string A, int start, string &current, vector<string> &result);
//an array of strings
string letter[]={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}; 

vector<string> Solution::letterCombinations(string A) {
    string current="";
    vector<string> result;
    combinations(A,0,current,result);
    return result;
}
void combinations(string A, int start, string &current, vector<string> &result){

    if(A.length()== start){
        //All digits are processed, so add current to result
        result.push_back(current);
        return;
    }
    //try all possible characters for this digit
    int digit= A[start]-'0';
    for(int i=0; i < letter[digit].length(); i++){
        current.push_back(letter[digit][i]);
        combinations(A,start+1, current, result);
        current.pop_back();
    }
    return;
}
