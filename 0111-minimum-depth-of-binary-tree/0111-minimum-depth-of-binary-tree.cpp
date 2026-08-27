/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        queue<TreeNode*> qu;

        qu.push(root);
        int curr = 1;

        while (!qu.empty()) {
            int n = qu.size();
            while (n--) {
                TreeNode* front = qu.front();
                qu.pop();

                if (!front->left && !front->right) {
                    return curr;
                }

                if (front->left) {
                    qu.push(front->left);
                }
                if (front->right) {
                    qu.push(front->right);
                }
            }
            curr++;
        }

        return curr;
    }
};