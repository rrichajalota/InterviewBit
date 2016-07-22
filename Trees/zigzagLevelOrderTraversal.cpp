/*  Zig Zag Level Order Traversal
    Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).
    Example : 
    Given binary tree

        3
       / \
      9  20
        /  \
       15   7
    return
    [
         [3],
         [20, 9],
         [15, 7]
    ]
*/
/*  Solution Approach
    Just reverse the entries in alternate rows!
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
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>> ans;
    vector<int> level;
    if(!A)
        return ans;
        
    queue<pair<TreeNode*, int>>q;
    
    q.push(make_pair(A,1));
    
    int prevheight= 1;
    stack<int> s;
    
    while(!q.empty()){
        
        pair<TreeNode*, int> p = q.front();
        TreeNode* current= p.first;
        int height= p.second;
        q.pop();
        
        if(height==prevheight)
            level.push_back(current->val);
            
        else if(height!= prevheight){
            
            if(prevheight % 2==0)
                reverse(level.begin(), level.end());
                
            ans.push_back(level);
            level.clear();
            level.push_back(current->val);
            prevheight= height;
        }
        
        if(current->left)
            q.push(make_pair(current->left, height+1));
        if(current->right)
            q.push(make_pair(current->right, height+1));
    }
    
    if(prevheight % 2==0)                   //print the last level
        reverse(level.begin(), level.end());
    ans.push_back(level);
    
    return ans;
}
