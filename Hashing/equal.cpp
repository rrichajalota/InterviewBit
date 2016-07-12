/*  Equal
    
    Given an array A of integers, find the index of values that satisfy A + B = C + D, where A,B,C & D are integers values in the array

    Note:

    1) Return the indices `A1 B1 C1 D1`, so that 
      A[A1] + A[B1] = A[C1] + A[D1]
      A1 < B1, C1 < D1
      A1 < C1, B1 != D1, B1 != C1 

    2) If there are more than one solutions, 
       then return the tuple of values which are lexicographical smallest. 
*/

vector<int> Solution::equal(vector<int> &A) {
    
    map<int, pair<int,int>>indices;   //stores the sum as key value and indices as pair
    vector<int> ans;
    
    for(int i=0; i< A.size(); i++){
        for(int j=i+1; j < A.size(); j++){
            
            int sum= A[i]+A[j];
            
            if(indices.find(sum)== indices.end()){
                indices[sum]= make_pair(i, j);
                continue;
            }
            
            pair<int, int> p1= indices[sum];    
            vector<int> temp;
            
            if(p1.first != i && p1.first != j && p1.second != i && p1.second != j){
                
                temp.push_back(p1.first);
                temp.push_back(p1.second);
                temp.push_back(i);
                temp.push_back(j);
            
                if(ans.size()==0)
                    ans= temp;
                    
                else{
                    bool shouldReplace = false;
                    
                    for (int k = 0; k < ans.size(); k++) {
                        if (ans[k] < temp[k]) break;
                        if (ans[k] > temp[k]) {     // if any index in ans > the index in temp
                            shouldReplace = true;   // the value of ans must be changed 
                            break;
                        }
                    }
                    
                    if (shouldReplace) ans = temp;
                }
            }
            
        }
    }
    return ans;
}
