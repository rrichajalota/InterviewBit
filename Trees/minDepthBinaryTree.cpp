/*  Minimum Depth of a Binary Tree

    Given a binary tree, find its minimum depth.
    The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
    NOTE : The path has to end on a leaf node. 
    Example :

             1
            /
           2
    min depth = 2.
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
 
int Solution::minDepth(TreeNode* A) {
    if(!A)
        return 0;
       
    queue< pair<TreeNode*, int>> q;
    q.push(make_pair(A,1));
    
    while(!q.empty()){
        
        pair<TreeNode*, int> p;    //stores the height of the node pointed by the current pointer
        p= q.front();
        TreeNode *current= p.first;
        int height= p.second;
        
        if(!current->left && !current->right)
            return height;
            
        if(current->left)
            q.push(make_pair(current->left,height+1));
        
        if(current->right)
            q.push(make_pair(current->right, height+1));
        
        q.pop();
    }
    
    return 0;
}
