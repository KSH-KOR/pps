#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 이진 검색 트리를 재구성하는 함수
TreeNode* buildBST(std::vector<int>& preorder, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(preorder[start]);

    int rightStart = start + 1;
    while (rightStart <= end && preorder[rightStart] < preorder[start]) {
        rightStart++;
    }

    root->left = buildBST(preorder, start + 1, rightStart - 1);
    root->right = buildBST(preorder, rightStart, end);

    return root;
}

// 후위 순회를 수행하는 함수
void postorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    std::cout << root->val << std::endl;
}

int main() {
    std::vector<int> preorder;
    int val;
    while (std::cin >> val) {
        preorder.push_back(val);
    }

    TreeNode* root = buildBST(preorder, 0, preorder.size() - 1);
    postorderTraversal(root);

    return 0;
}
