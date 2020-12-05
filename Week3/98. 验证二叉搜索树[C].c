int getMax(struct TreeNode* root){
    if (root->right == NULL) return root->val;
    return getMax(root->right);
}

int getMin(struct TreeNode* root){
    if (root->left == NULL) return root->val;
    return getMin(root->left);
}

bool isValidBST(struct TreeNode* root){
    if (root == NULL) return true;
    if (root->left == NULL && root->right == NULL) return true;
    else if (root->left == NULL){
        if (isValidBST(root->right) && root->val < getMin(root->right))
            return true;
    }
    else if (root->right == NULL){
        if (isValidBST(root->left) && root->val > getMax(root->left))
            return true;
    }
    else{
        if (isValidBST(root->left) && isValidBST(root->right)){
            if (root->val > getMax(root->left) && root->val < getMin(root->right))
                return true;
        }
    }
    return false;
}