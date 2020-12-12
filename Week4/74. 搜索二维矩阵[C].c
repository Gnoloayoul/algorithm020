//binary search
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    if( matrixSize  == 0 ) return false;
    int lo = 0;
    int clm = matrixColSize[0];
    int hi =  clm * matrixSize - 1;
    
    while(lo <= hi) {
        int mid = lo + (hi - lo)/2;
        int rw = mid / clm;
        int cl = mid % clm;
        if(matrix[rw][cl] == target) return true;
        if(matrix[rw][cl] > target) hi = mid - 1;
        else lo = mid + 1;
    }
    return false;
}