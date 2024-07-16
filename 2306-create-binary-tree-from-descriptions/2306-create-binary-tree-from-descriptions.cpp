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
    TreeNode* newNode(int d) {
        TreeNode* temp = new TreeNode;
        temp->val = d;
        temp->left = nullptr;
        temp->right = nullptr;
        return temp;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        for (auto it : descriptions) {
            TreeNode *parent, *child;
            if (mp.find(it[0]) != mp.end()) {
                parent = mp[it[0]];
            } else {
                parent = newNode(it[0]);
                mp[it[0]] = parent;
            }

            if (mp.find(it[1]) != mp.end()) {
                child = mp[it[1]];
            } else {
                child = newNode(it[1]);
                mp[it[1]] = child;
            }

            if (it[2] == 1) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        }
        unordered_map<int, int> storeChild;
        for (auto it : descriptions) {
            storeChild[it[1]] = 1;
        }

        // Find the root of the Tree
        TreeNode* root;
        for (auto it : descriptions) {
            if (storeChild.find(it[0]) == storeChild.end()) {
                root = mp[it[0]];
            }
        }
        return root;
    }
};