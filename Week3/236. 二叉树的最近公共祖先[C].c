struct TreeNode * find(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q, bool * judge);
    
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    bool judge = false;
    return find(root, p, q, &judge);
}

struct TreeNode * find(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q, bool * judge){
    if (root == NULL)
        return NULL;
    bool left_judge = false;
    bool right_judge = false;
    struct TreeNode* root_l = NULL;
    struct TreeNode* root_r = NULL;
    if (root == p || root == q){
        //printf("%d\n", root->val);
        *judge = true;
    }
    
    root_l = find(root->left, p, q, &left_judge);
    root_r = find(root->right, p, q, &right_judge);
    if (root_l != NULL)
        return root_l;
    if (root_r != NULL)
        return root_r;
    if (left_judge && right_judge)
        return root;
    if (*judge == true)
        if (left_judge == true || right_judge == true)
            return root;
    if (*judge == false)
        *judge = (left_judge || right_judge);
    return NULL;
}