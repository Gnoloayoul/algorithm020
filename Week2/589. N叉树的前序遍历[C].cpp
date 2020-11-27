void func(struct Node* root, int* res, int* resSize) {
    if (root == NULL) return;
    res[(*resSize)++] = root->val;
    for (int i = 0; i < root->numChildren; i++) {
        func(root->children[i], res, resSize);
    }
}

int* preorder(struct Node* root, int* returnSize) {
    int* res = (int*)malloc(sizeof(int) * 10000);
    *returnSize = 0;
    func(root, res, returnSize);
    return res;
}