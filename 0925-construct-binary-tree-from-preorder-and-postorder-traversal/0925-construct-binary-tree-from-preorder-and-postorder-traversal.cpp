class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> postIndex; // Store indices of postorder elements
        for (int i = 0; i < postorder.size(); i++) {
            postIndex[postorder[i]] = i;
        }
        int preIndex = 0;
        return buildTree(preorder, postorder, preIndex, 0, postorder.size() - 1, postIndex);
    }

private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder, int& preIndex, int left, int right, unordered_map<int, int>& postIndex) {
        if (preIndex >= preorder.size() || left > right) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[preIndex++]);

        if (left == right) return root; // Leaf node case

        int leftSubtreeRoot = preorder[preIndex];
        int postLeftIndex = postIndex[leftSubtreeRoot];

        root->left = buildTree(preorder, postorder, preIndex, left, postLeftIndex, postIndex);
        root->right = buildTree(preorder, postorder, preIndex, postLeftIndex + 1, right - 1, postIndex);

        return root;
    }
};
