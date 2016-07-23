/*  Construct Binary Tree From Inorder And Postorder
    Given inorder and postorder traversal of a tree, construct the binary tree.
    Note: You may assume that duplicates do not exist in the tree. 
    Example :
    Input : 
            Inorder : [2, 1, 3]
            Postorder : [2, 3, 1]

    Return : 
                1
               / \
              2   3
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
TreeNode* buildtree(vector<int> &inorder, vector<int> &postorder, int low, int high);

TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {

    if(inorder.size()==0 && postorder.size()==0)
        return NULL;

    return buildtree(inorder,postorder,0, inorder.size()-1);
}

TreeNode* buildtree(vector<int> &inorder, vector<int> &postorder, int low, int high){

    TreeNode *root= NULL;
    int psize= postorder.size();
    int mid;

    if(low<=high){

        for (int i=low; i <= high; i++){

            if(inorder[i]==postorder[psize-1]){
                mid= i;
                break;
            }

        }

        TreeNode* temp= new TreeNode(inorder[mid]);
        root= temp;
        postorder.resize(psize-1);
    }

    else 
        return NULL;
    
    root->right= buildtree(inorder,postorder,mid+1,high);
    root->left= buildtree(inorder,postorder,low, mid-1);
    
    return root;
}