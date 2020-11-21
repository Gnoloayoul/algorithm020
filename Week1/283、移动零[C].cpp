void moveZeroes(int* nums, int numsSize) {
    int j = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0)
            nums[j++] = nums[i];
    }
    for (int i = j; i < numsSize; i++) {
        nums[i] = 0;
    }
}

//������
//1��
//���룺[0,1,0,3,12]
//Ԥ�ڽ����[1,3,12,0,0]
//ʵ�ʽ����[1,3,12,0,0]