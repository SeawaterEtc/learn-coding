//...  
/*
Certainly! Let's break down the problem and write the C++ functions for the tasks you've described.

1. **Function to Calculate Tree Height:**
   To calculate the height of a binary tree, we can use a recursive approach. The height of a binary tree is the length of the longest path from the root to any leaf node. Here's how you can implement it:

    ```cpp
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    int calculateHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0; // Base case: empty tree has height 0
        }
        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);
        return 1 + std::max(leftHeight, rightHeight);
    }
    ```

2. **Function to Calculate Sum Value of Each Node and Its Children:**
   To compute the sum of values for each node and its children, we can use a similar recursive approach. Here's how you can implement it:

    ```cpp
    int calculateSum(TreeNode* root) {
        if (root == nullptr) {
            return 0; // Base case: empty tree has sum 0
        }
        int leftSum = calculateSum(root->left);
        int rightSum = calculateSum(root->right);
        return root->val + leftSum + rightSum;
    }
    ```

3. **Function to Sum the Value of Subtree:**
   If you want to find the sum of values in a specific subtree rooted at a given node, you can modify the previous function to start from that node. For example:

    ```cpp
    int subtreeSum(TreeNode* root) {
        if (root == nullptr) {
            return 0; // Base case: empty subtree has sum 0
        }
        int leftSubtreeSum = subtreeSum(root->left);
        int rightSubtreeSum = subtreeSum(root->right);
        return root->val + leftSubtreeSum + rightSubtreeSum;
    }
    ```

Remember to create a binary tree with appropriate values and call these functions accordingly. Feel free to adapt the code to your specific use case! 😊
*/