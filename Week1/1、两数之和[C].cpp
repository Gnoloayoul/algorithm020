int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i, j, * arr;
    for (i = 0; i < numsSize - 1; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                arr = (int*)malloc(2 * sizeof(int));
                arr[0] = i;
                arr[1] = j;
                *returnSize = 2;
                return arr;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

//������
//1��
//���룺[2,7,11,15] 9
//Ԥ�ڽ����[0,1]
//ʵ�ʽ����[0,1]