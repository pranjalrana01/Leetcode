class Solution
{
private:
    TreeNode *find(TreeNode *root, TreeNode *curr)
    {
        while (root->right && root->right != curr)
        {
            root = root->right;
        }
        return root;
    }
    void morris_traversal(TreeNode *root, int k, int &count, int &ans)
    {
        if (root == NULL)
        {
            return;
        }

        TreeNode *curr = root;
        while (curr)
        {

            if (curr->left == NULL)
            {
                count = count + 1;
                if (count == k)
                {
                    ans = curr->val;
                }
                curr = curr->right;
            }
            else
            {
                TreeNode *pred = find(curr->left, curr);
                if (pred->right == NULL)
                {
                    pred->right = curr;
                    curr = curr->left;
                }
                else
                {
                    count = count + 1;
                    if (count == k)
                    {
                        ans = curr->val;
                    }
                    pred->right = NULL;
                    curr = curr->right;
                }
            }
        }
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        int count = 0;
        int ans = -1;
        morris_traversal(root, k, count, ans);
        return ans;
    }
};