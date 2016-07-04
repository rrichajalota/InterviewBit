/*  3 Sum Zero
    Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
    Find all unique triplets in the array which gives the sum of zero.

    Note:

    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
    The solution set must not contain duplicate triplets. For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:
    (-1, 0, 1)
    (-1, -1, 2) 

*/
vector<vector<int> > Solution::threeSum(vector<int> &A) {
    vector<vector<int>> ans;
    vector<int> sum(3);
    
    if(A.size() < 3)   // if condition is not checked, it will give a runtime error 
        return ans;
        
    sort(A.begin(), A.end());   // sort the array first
    for(int i=0; i < A.size() - 2; i++){ 
        
        while(i > 0 && A[i]== A[i-1])   //make sure to not process the same triplets again. 
            ++i;                        // if A[i]== A[i-1] then all possibilities for A[i] would have 
                                        // already been explored
        int j=i+1, k=A.size()-1;
        while(j < k){                   
            
            if(A[i]+ A[j]+ A[k] == 0){
                
                sum[0]= A[i], sum[1]= A[j], sum[2]= A[k];
                
                if(ans.size()==0)
                    ans.push_back(sum);
                    
                else if (ans[ans.size()-1] != sum)
                    ans.push_back(sum);
                    
                ++j;                             // we can also decrement k instead of increasing j
                while(A[j]==A[j-1] && j < k)    // check for duplicates 
                    ++j;
            }
            else if(A[i]+ A[j]+ A[k] < 0){      // if sum < 0 then increment j
                ++j; 
            }
            else --k;                           // else decrement k
        }
    }
    return ans;
}
