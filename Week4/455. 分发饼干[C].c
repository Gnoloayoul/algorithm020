//greedy
int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int findContentChildren(int* g, int gSize, int* s, int sSize)
{
    if(gSize == 0 || sSize == 0)
    {
        return 0;
    }
    qsort(g, gSize, sizeof(int), compare);
    qsort(s, sSize, sizeof(int), compare);
    
    int child = 0;
    int cookie = 0;
    
    while(child < gSize && cookie < sSize)
    {
        if(s[cookie] >= g[child])
        {
            child++;
            cookie++;
        }
        else
        {
            cookie++;
        }
    }
    
    return child;
}