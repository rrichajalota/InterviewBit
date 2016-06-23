/*  InterviewBit- Add one to a number
    Given a non-negative number represented as an array of digits,
    add 1 to the number ( increment the number represented by the digits ).
    The digits are stored such that the most significant digit is at the head of the list.
    
    Example:
    If the vector has [1, 2, 3]
    the returned vector should be [1, 2, 4]
    as 123 + 1 = 124.

    NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer.
    For example, for this problem, following are some good questions to ask :
    Q : Can the input have 0’s before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
    A : For the purpose of this question, YES
    Q : Can the output have 0’s before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
    A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.

*/
vector<int> Solution::plusOne(vector<int> &A) {

    ++A.back();             // add one at the LSD
    for (int i = A.size()-1; i > 0 && A[i]==10; --i){
        A[i]= 0;
        A[i-1]= A[i-1]+1;
    }
    if (A[0]==10){
        A[0]=1;
        A.push_back(0);
    }
    int i=0;
    int countzeros=0;      //count the number of 0s before the MSD
    while (A[i]==0){
        countzeros++;
        i++;
    }
    if(countzeros!=0){
        reverse(A.begin(), A.end());    
        A.resize(A.size()-countzeros);
        reverse(A.begin(), A.end());
    }
    return A;
    
}
