/*  Grid Unique Paths

    A robot is located at the top-left corner of an A x B grid (marked ‘Start’ in the diagram below).
    The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the diagram below).

    How many possible unique paths are there?

    Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.

    Example :

    Input : A = 2, B = 2
    Output : 2

    2 possible routes : (0, 0) -> (0, 1) -> (1, 1) 
                  OR  : (0, 0) -> (1, 0) -> (1, 1)

*/

/*  SOLUTION USING DYNAMIC PROGRAMMING
    At every position, we can reach either from above or from left. So ways of reaching (i,j) will be equal to the sum of ways from (i,j-1) and
    ways from (i-1,j).
*/

int Solution::uniquePaths(int A, int B) {
    vector<vector<int>> v(A, vector<int>(B));
    
    for(int i=0; i< A; i++){
        v[i][0]=1;
    }
    
    for(int j=0; j < B; j++){
        v[0][j]=1;
    }
    
    for(int i=1; i < A; i++){
        for(int j=1; j < B; j++){
            v[i][j]= v[i-1][j]+ v[i][j-1];
        }
    }
    
    return v[A-1][B-1];
}