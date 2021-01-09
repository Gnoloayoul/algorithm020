uint32_t reverseBits(uint32_t n) {
    int result = 0, ct = 31;
    while (ct) {
        result = (result + (n & 1)) << 1;
        n >>= 1;
        ct--;
    }
    result = result + (n & 1);
    return result;
}