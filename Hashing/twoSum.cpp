/* TWO SUM
    Given an array of integers, find two numbers such that they add up to a specific target number.

    The function twoSum should return indices of the two numbers such that they add up to the target, where index1 < index2. Please note that your returned answers (both index1 and index2 ) are not zero-based. 
    Put both these numbers in order in an array and return the array from your function ( Looking at the function signature will make things clearer ). Note that, if no pair exists, return empty list.

    If multiple solutions exist, output the one where index2 is minimum. If there are multiple solutions with the minimum index2, choose the one with minimum index1 out of them.

    Input: [2, 7, 11, 15], target=9
    Output: index1 = 1, index2 = 2
*/

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    unordered_map<int,int> index; //store the index in the hashtable
    vector<int> ans;

    for(int i=0; i< A.size(); i++){
        
        int diff= B- A[i];
        
        if(index.find(diff) != index.end()){
            ans.push_back(index[diff]);
            ans.push_back(i+1);
            return ans;
        }

        if(index.find(A[i])== index.end())      //we need to store the minimum index1. consider the case where A= [1 1 1 2] and B=3 
            index[A[i]]= i+1;                   // then output should be [1,4]

    }
    return ans;
}
