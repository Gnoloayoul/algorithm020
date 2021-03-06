void helper(int* nums, int numsSize, int** result, int* resultIdx, int* tempBuffer, int tempSize)
{
    int i,j;
    
    if(tempSize == numsSize)
    {
        memcpy(result[(*resultIdx)++],tempBuffer,numsSize*sizeof(int));
    }
    else
    {
        for(i=0;i<numsSize;i++)
        {
            for(j=0;j<tempSize;j++)
            {
                if(tempBuffer[j] == nums[i])
                    break;
            }
            if(j<tempSize)
                continue;
            
            tempBuffer[tempSize] = nums[i];
            helper(nums, numsSize, result, resultIdx, tempBuffer, tempSize+1);
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int** result;
    int resultIdx = 0;
    int count = 1;
    int i;
    int* tempBuffer = (int*)malloc(numsSize*sizeof(int));
    int tempSize = 0;
    
    for(i=1;i<=numsSize;i++)
        count *= i;
    
    result = (int**)malloc(count*sizeof(int*));
    (*returnColumnSizes) = (int*)malloc(count*sizeof(int));
    for(i=0;i<count;i++)
    {
        result[i] = (int*)malloc(numsSize*sizeof(int));
        (*returnColumnSizes)[i] = numsSize;
    }
    helper(nums,numsSize,result,&resultIdx,tempBuffer,tempSize);
    
    *returnSize = count;
    return result;
}