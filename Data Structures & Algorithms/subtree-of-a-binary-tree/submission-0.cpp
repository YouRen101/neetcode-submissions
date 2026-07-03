class Solution {
public:
    int height_of_tree(TreeNode* subRoot){
        if(!subRoot) return 0;
        return max(height_of_tree(subRoot->left) , height_of_tree(subRoot->right)) + 1;
    }

    bool check(TreeNode* root , TreeNode* subRoot){
        if(!root && !subRoot) return 1;
        if(!root || !subRoot) return 0;

        if(root->val != subRoot->val) return 0;
        return check(root->left , subRoot->left) && 
            check(root->right , subRoot->right);
    }

    vector<TreeNode*> q;
    int deep(TreeNode* root , int& h){
        if(!root) return 0;
        int depth = max(deep(root->left , h) , deep(root->right , h)) + 1;
        if(depth == h)
            q.push_back(root);
        return depth;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        int hs = height_of_tree(subRoot);
        int hr = deep(root , hs);

        for(auto& nd : q){
            if(check(nd , subRoot)) return 1;
        }

        return 0;
    }
};
