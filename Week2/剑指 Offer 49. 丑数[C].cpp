int nthUglyNumber(int n) {
    int* uglyNums = (int*)malloc(n * sizeof(int));
    uglyNums[0] = 1;
    int index2 = 0, index3 = 0, index5 = 0;
    int factor2 = 2, factor3 = 3, factor5 = 5;
    for (int i = 1; i < n; i++) {
        int temp = factor2 < factor3 ? factor2 : factor3;
        int min = temp < factor5 ? temp : factor5;
        uglyNums[i] = min;
        if (min == factor2) {
            factor2 = 2 * uglyNums[++index2];
        }
        if (min == factor3) {
            factor3 = 3 * uglyNums[++index3];
        }
        if (min == factor5) {
            factor5 = 5 * uglyNums[++index5];
        }
    }
    return uglyNums[n - 1];
}           