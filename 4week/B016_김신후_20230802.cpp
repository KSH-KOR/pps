
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* newRoot = nullptr;
        TreeNode* currNode = nullptr;

        inorderTraversal(root, newRoot, currNode);
        return newRoot;
    }

    void inorderTraversal(TreeNode* root, TreeNode*& newRoot, TreeNode*& currNode) {
        if (!root)
            return;

        inorderTraversal(root->left, newRoot, currNode);

        if (!newRoot) {
            newRoot = root;
            currNode = root;
        } else {
            currNode->right = root;
            currNode = currNode->right;
            root->left = nullptr;
        }

        inorderTraversal(root->right, newRoot, currNode);
    }
};
