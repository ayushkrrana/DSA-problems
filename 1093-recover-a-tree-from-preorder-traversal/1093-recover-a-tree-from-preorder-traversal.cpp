class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<pair<TreeNode*, int>> st;  // Stack to store nodes with their depths
        int i = 0, n = traversal.size();

        while (i < n) {
            int depth = 0;
            while (i < n && traversal[i] == '-') { // Count dashes (depth)
                depth++;
                i++;
            }

            int val = 0;
            while (i < n && isdigit(traversal[i])) { // Extract node value
                val = val * 10 + (traversal[i] - '0');
                i++;
            }

            TreeNode* node = new TreeNode(val);

            while (!st.empty() && st.top().second >= depth) {
                st.pop();  // Pop elements until the correct parent is found
            }

            if (!st.empty()) { // Attach as child of the last valid parent
                TreeNode* parent = st.top().first;
                if (!parent->left) parent->left = node;
                else parent->right = node;
            }

            st.push({node, depth});  // Push current node with its depth
        }

        while (st.size() > 1) st.pop(); // Root remains at the bottom
        return st.top().first; // Return root
    }
};
