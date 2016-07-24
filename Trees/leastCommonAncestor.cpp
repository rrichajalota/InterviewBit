/*  Least Common Ancestor
    Find the lowest common ancestor in an unordered binary tree given two values in the tree.
    Example :
        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2_     0        8
         /   \
         7    4
    For the above tree, the LCA of nodes 5 and 1 is 3.
    LCA for nodes 5 and 4 is 5.

    You are given 2 values. Find the lowest common ancestor of the two nodes represented by val1 and val2
    No guarantee that val1 and val2 exist in the tree. If one value doesn’t exist in the tree then return -1.
    There are no duplicate values.

    You can use extra memory, helper functions, and can modify the node struct but, you can’t add a parent pointer.
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* SOLUTION APPROACH
    Linear solution using path calculation :
    1) Find path from root to n1 and store it in a vector or array.
    2) Find path from root to n2 and store it in another vector or array.
    3) Traverse both paths till the values in arrays are same. Return the common element just before the mismatch
*/

void findpath(TreeNode* A, int val, vector<int> &p, bool &found);

int Solution::lca(TreeNode* A, int val1, int val2) {
    
    if(!A)
        return -1;
        
    vector<int> p1, p2;
    bool found= false;
    findpath(A,val1,p1,found);
    found= false;
    findpath(A,val2,p2,found);
    
    if(p1.size()==0 || p2.size()==0)
        return -1;
        
    else{
        if(p1.size()!=p2.size())
            p1.size() > p2.size() ? p1.resize(p2.size()) : p2.resize(p1.size());
            
        for(int i= p1.size()-1; i >= 0; --i){
            if(p1[i]==p2[i])
                return p1[i];
        }
    }
    return -1;
}

void findpath(TreeNode* A, int val, vector<int> &p, bool &found){
    
    if(!A)
        return;
        
    p.push_back(A->val);
    
    if(A->val != val){

        findpath(A->left,val,p,found);
        
        if(!found){
            findpath(A->right,val,p,found);
            
            if(!found)
                p.pop_back();
                
            else return;
        }
        else return;
    }
    
    else{ 
        found= true;
        return;
    }
}
