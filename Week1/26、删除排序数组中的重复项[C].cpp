int removeDuplicates(int* nums, int numsSize) {
    for (i = 1, j = 0; i < numsSize; i++)
        if (nums[i - 1] != nums[i]) { nums[++j] = nums[i]; }
    return (numsSize > 0 ? j + 1 : j);
}

//������
//1��
//���룺[0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 5, 7, 7, 7, 7]
//Ԥ�ڽ����[0, 1, 2, 3, 4, 5, 7]
//ʵ�ʽ����[0, 1, 2, 3, 4, 5, 7]