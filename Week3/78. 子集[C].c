void helper(int* nums, int len, int* rsize, int* *rcsizes, int** *ans, int ptr, int _len) {
    if (_len >= len || ptr >= len) return;  
    int prev = *rsize-1;

    for (int q = ptr; q < len; q++){ 
        (*rcsizes)[*rsize] = _len+1;
        (*ans)[*rsize] = malloc(sizeof(int) * (*rcsizes)[*rsize]);
        
        memcpy((*ans)[*rsize], (*ans)[prev], sizeof(int) *_len); 
           
        (*ans)[*rsize][_len] = nums[q]; 

        (*rsize)++; 

        helper(nums, len, rsize, rcsizes, ans, q + 1, _len + 1); 
    } 
}

int** subsets(int* nums, int len, int* rsize, int* *rcsizes){
    *rcsizes = malloc(sizeof(int) * pow(2, len));
    (*rcsizes)[0] = 0; 
    
    int* *ans = malloc(sizeof(int*) * pow(2, len));
    
    *rsize = 1;

    helper(nums, len, rsize, rcsizes, &ans, 0, 0); 

    return ans;
}