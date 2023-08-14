#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Mid 199 https://leetcode.cn/problems/binary-tree-right-side-view/
class Solution {
public:
    vector<int> res;

    vector<int> rightSideView(TreeNode *root) {
        traversal(root, 0);
        return res;
    };

    void traversal(TreeNode *root, int deep) {
        if (root == nullptr) { return; }
        if (res.size() == deep) { res.push_back(root->val); }
        traversal(root->right, deep + 1);
        traversal(root->left, deep + 1);
    }

};