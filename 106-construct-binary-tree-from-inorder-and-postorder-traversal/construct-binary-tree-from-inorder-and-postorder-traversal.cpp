class Solution {
public:
    TreeNode* solve(vector<int>& inorder, int startin, int endin, vector<int>& postorder, int startpost, int endpost){
        if (startin > endin || startpost > endpost) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(postorder[endpost]);
        int index;
        for(index=startin; index<=endin; ++index){
            if(inorder[index] == root -> val){
                break;
            }
        }
        int leftsize = index - startin;
        root -> left = solve(inorder, startin, index-1, postorder, startpost, startpost+leftsize-1);
        root -> right = solve(inorder, index+1, endin, postorder, startpost+leftsize, endpost-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
       return solve(inorder, 0, n-1, postorder,0, n-1);

    }
};