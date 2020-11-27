#define PROT_READ           0x1
#define PROT_WRITE          0x2
#define MAP_ANONYMOUS       0x20  
#define MAP_PRIVATE         0x02
#define MAP_FAILED          ((void *)-1)
extern void* mmap(void* addr, size_t length, int prot, int flags, int fd, off_t offset);

#define NUM_ELEMS           80000000ULL

struct elem { uint8_t f; struct elem* p, * n; };

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int* ans = malloc(sizeof(int[numsSize])), j = 0;
    struct elem* e = mmap(NULL, sizeof(struct elem[NUM_ELEMS]), PROT_READ | PROT_WRITE,
        MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    struct elem* a = e + NUM_ELEMS / 2;
    struct elem* ft[256] = { NULL };
    int mxf = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        int n = nums[i];
        int pf = a[n].f++;
        int nf = a[n].f;
        ft[pf] == &a[n] ? ft[pf] = ft[pf]->n : 0;
        a[n].p ? a[n].p->n = a[n].n : 0;
        a[n].n ? a[n].n->p = a[n].p : 0;
        a[n].p = NULL;
        a[n].n = ft[nf];
        ft[nf] ? ft[nf]->p = &a[n] : 0;
        ft[nf] = &a[n];
        mxf < nf ? mxf = nf : 0;
    }
    for (int i = mxf; k && i >= 0; i--)
        for (struct elem* c = ft[i]; c && k--; ans[j++] = c - a, c = c->n);
    return munmap(e), * returnSize = j, ans;
}