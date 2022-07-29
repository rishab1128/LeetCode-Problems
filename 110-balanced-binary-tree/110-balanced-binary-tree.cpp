class Solution {
private:
  
  bool isBalancedTreeHelper(TreeNode* root, int& height) {
   
    if (root == NULL) {
      height = 0;
      return true;
    }

   
    int left, right;
    if (isBalancedTreeHelper(root->left, left)  &&
        isBalancedTreeHelper(root->right, right) &&
        abs(left - right) < 2) {
      // Store the current tree's height
      height = max(left, right) + 1;
      return true;
    }
    return false;
  }
public:
  bool isBalanced(TreeNode* root) {
    int height;
    return isBalancedTreeHelper(root, height);
  }
};