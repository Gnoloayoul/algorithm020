int minDepth(struct TreeNode* root) {
    if (!root) return 0;
    int L = minDepth(root->left), R = minDepth(root->right);
    return L < R && L || !R ? 1 + L : 1 + R;
}