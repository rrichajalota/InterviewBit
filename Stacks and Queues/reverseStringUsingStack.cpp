/*  Reverse a string using stack
    Given a string S, reverse the string using stack.

    Example :

    Input : "abc"
    Return "cba"
*/

string Solution::reverseString(string A) {
    stack<char> s;
    string rev= "";
    for(int i = 0; A[i] != '\0'; i++){
        s.push(A[i]);
    }
    while(!s.empty()){
        rev += s.top();
        s.pop();
    }
    return rev;
}
