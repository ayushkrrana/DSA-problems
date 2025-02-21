#include <unordered_set>

class FindElements {
private:
    unordered_set<int> recoveredValues;
    
    // Function to recover tree values
    void recover(TreeNode* node, int val) {
        if (!node) return;
        
        node->val = val;
        recoveredValues.insert(val);
        
        recover(node->left, 2 * val + 1);
        recover(node->right, 2 * val + 2);
    }
    
public:
    FindElements(TreeNode* root) {
        if (root) {
            recover(root, 0);
        }
    }
    
    bool find(int target) {
        return recoveredValues.count(target);
    }
};
