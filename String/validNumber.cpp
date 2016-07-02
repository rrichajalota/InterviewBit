/*  VALID NUMBER
    Validate if a given string is numeric.

    Examples:

    "0" => true
    " 0.1 " => true
    "abc" => false
    "1 a" => false
    "2e10" => true
    Return 0 / 1 ( 0 for false, 1 for true ) for this problem

    Clarify the question using “See Expected Output”

    Is 1u ( which may be a representation for unsigned integers valid?
    For this problem, no.
    Is 0.1e10 valid?
    Yes
    -01.1e-10?
    Yes
    Hexadecimal numbers like 0xFF?
    Not for the purpose of this problem
    3. (. not followed by a digit)?
    No
    Can exponent have decimal numbers? 3e0.1?
    Not for this problem.
    Is 1f ( floating point number with f as prefix ) valid?
    Not for this problem.
    How about 1000LL or 1000L ( C++ representation for long and long long numbers )?
    Not for this problem.
    How about integers preceded by 00 or 0? like 008?
    Yes for this problem

*/

int Solution::isNumber(const string &A) {
    int i =0;
    while(A[i]== ' ' && A[i] != '\0'){
        ++i;
    }
    if(A[i]=='\0')
        return 0;
        
    if(A[i]== '+' || A[i]== '-') //skip the sign
        ++i;
        
    int dots=0, digits=0;
    
    for(dots=0, digits=0; A[i]>='0' && A[i]<='9' || A[i]=='.'; ++i){
        if(A[i]>='0' && A[i]<='9')
            ++digits;
        if(A[i]=='.')
            ++dots;
    }
    
    if(dots > 1 || digits==0 || A[i-1]== '.')       //more than 1 dots not allowed
        return 0;
        
    if(A[i]=='e'){
        ++i;
        if(A[i]== '+' || A[i]== '-') //skip the sign
            ++i;
        for(digits=0; A[i]>='0' && A[i]<='9'; ++i)
            ++digits;
        if(digits==0)
            return 0;
    }
    while(A[i]== ' ' && A[i]!= '\0')
        ++i;
        
    if(A[i]== '\0')
        return 1;
        
    return 0;
}
