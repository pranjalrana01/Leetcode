/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     uint64_t val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(uint64_t x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(uint64_t x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    uint64_t widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        uint64_t ans = 0;

        queue<pair<TreeNode*,uint64_t>>q;
        q.push({root,0});
        while(!q.empty()){
            uint64_t size = q.size();
            uint64_t min = q.front().second;
            uint64_t first, last;

            for(uint64_t i=0 ; i<size; i++){
                uint64_t curr_id = q.front().second - min;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0) first = curr_id;
                if(i==size-1) last = curr_id;

                if(node -> left){
                    q.push({node -> left, curr_id*2+1});
                }

                if(node -> right){
                    q.push({node -> right, curr_id*2+2});
                }
                ans = max(ans, last-first+1);
            }
        }
        return ans;
    }
};