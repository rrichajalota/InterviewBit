/*  COLORFUL NUMBER
    For Given Number N find if its COLORFUL number or not
    Return 0/1

    COLORFUL number:
    A number can be broken into different sub-sequence parts. 
    Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
    And this number is a COLORFUL number, since product of every digit of a sub-sequence are different
    Example:

    N = 23
    2 3 23
    2 -> 2
    3 -> 3
    23 -> 6
    this number is a COLORFUL number since product of every digit of a sub-sequence are different. 
    Output : 1
*/

int Solution::colorful(int A) {

    int size= log10(A)+1;                //calculate the no. of digits in the integer
    vector<int> v(size);                // create an array of the same size
    int divisor= int(pow(10, size-1)), i=0;
    map<int,bool> present;
    
    while(A){
        v[i++]= A/divisor;
        A %= divisor;
        divisor /= 10;
    }
    
    for(i=0; i< size; i++){
        int product= 1;
        for(int j=i; j < size; j++){
            
            if(i==j)
                product= v[j];
                
            else product= product*v[j];
            
            if(present[product]==1)
                return 0;
            else present[product]= 1;
        }
    }
    return 1;
}
