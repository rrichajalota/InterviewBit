/*  PRETTY PRINT- Level up

    Print concentric rectangular pattern in a 2d matrix. 
    Let us show you some examples to clarify what we mean.

    Example 1:
    Input: A = 4.

    Output:
    4 4 4 4 4 4 4 
    4 3 3 3 3 3 4 
    4 3 2 2 2 3 4 
    4 3 2 1 2 3 4 
    4 3 2 2 2 3 4 
    4 3 3 3 3 3 4 
    4 4 4 4 4 4 4 

    Example 2:
    Input: A = 3.

    Output:
    3 3 3 3 3 
    3 2 2 2 3 
    3 2 1 2 3 
    3 2 2 2 3 
    3 3 3 3 3 

    The outermost rectangle is formed by A, then the next outermost is formed by A-1 and so on.
    You will be given A as an argument to the function you need to implement, and you need to return a 2D array.

*/

vector<vector<int> > Solution::prettyPrint(int A) {
    int n=1;
    for(int i= 2; i <= A; i++){
        n += 2;
    }
    
    vector<vector<int>> v(n, vector<int>(n));
    
    if (A == 1){
        v[0][0]= 1;
        return v;
    }
    
    int start= 0, end= n-1;
    
    while (A >= 1){
        int i= start, j;
        for(j= start; j < end; j++)
            v[i][j]= A;
        for(i= start; i< end; i++)
            v[i][j]= A;
        for(j= end; j > start; --j)
            v[i][j]= A;
        for(i= end; i > start; --i)
            v[i][j]= A;
            
        A= A-1;
        start= start+1;
        end= end-1;
        
        if(start== end && A==1){
            v[start][end]= 1;
            break;
        }
    }
    return v;
}
