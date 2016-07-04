/*	Array 3 pointers
	You are given 3 arrays A, B and C. All 3 of the arrays are sorted.

	Find i, j, k such that :
	max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.
	Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i]))

	**abs(x) is absolute value of x and is implemented in the following manner : **

	      if (x < 0) return -x;
	      else return x;
	Example :

	Input : 
	        A : [1, 4, 10]
	        B : [2, 15, 20]
	        C : [10, 12]

	Output : 5 
         With 10 from A, 15 from B and 10 from C. 
*/

/*	Solution Approach
	We increment the pointer of the array which has the minimum, because our goal is to decrease the difference. Increasing the maximum pointer is definitely going to increase the difference. Increase the second maximum pointer can potentially increase the difference ( however, it certainly will not decrease the difference ).
*/

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    
    int mindiff=INT_MAX, i=0, j=0, k=0;
    
    while(i < A.size() && j< B.size() && k < C.size()){
        
        int num= max(abs(A[i] - B[j]), max(abs(B[j] - C[k]), abs(C[k] - A[i])));
        mindiff= min(num, mindiff);
        
        if(A[i] <= B[j] && A[i] <= C[k]){
            ++i;
        }
        
        else if(B[j] <= A[i] && B[j] <= C[k])
            ++j;
            
        else ++k;
    }
    return mindiff;
}
