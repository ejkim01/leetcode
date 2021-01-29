/*
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as:
a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
Example 1:
Given the following tree [3,9,20,null,null,15,7]:
   3
   / \
  9  20
    /  \
   15   7
Return true.
 
Example 2:
Given the following tree [1,2,2,3,3,null,null,4,4]:
      1
      / \
     2   2
    / \
   3   3
  / \
 4   4

Return false.
*/

bool isBalanced(TreeNode *root) {
    if (!root) return true;
    if (abs(getDepth(root->left) - getDepth(root->right)) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);    
}
int getDepth(TreeNode *root) {
    if (!root) return 0;
    return 1 + max(getDepth(root->left), getDepth(root->right));
}