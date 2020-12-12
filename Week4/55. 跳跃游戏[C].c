bool canJump(int* nums, int numsSize) {
    int max = 0;
    for(int i =0; i<numsSize-1 && max < numsSize; i++)   {
        max = ((i+nums[i]) > max)? i+nums[i] : max;
        if(max < i+1)  return false;
    }
    return true;
}