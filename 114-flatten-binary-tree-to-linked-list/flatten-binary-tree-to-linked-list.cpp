class Solution {
public:
    void flatten(TreeNode* root) {

        if(root == nullptr) return;
        TreeNode* current = root;

        while(current != nullptr){
            
            if(current->left){
                TreeNode* prev = current->left;

                while(prev->right){
                    prev = prev->right;
                }

                prev->right = current->right;
                current->right = current->left;
                current->left = nullptr;

            }

            current = current->right;
        }        
    }
};