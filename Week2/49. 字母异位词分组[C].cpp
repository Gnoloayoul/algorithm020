/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define KEYLEN 26
typedef struct {
    uint8_t key[KEYLEN];
    int listSize;
    char** list;
    UT_hash_handle hh;
} Map;

void create_freq_map(char* str, uint8_t* fm) {
    for (int i = 0; str[i] != 0; i++)
        fm[str[i] - 'a']++;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    Map* map = NULL, * elem = NULL, * tmp;
    uint8_t freqMap[KEYLEN];
    char*** result = NULL;
    int mapIndx = 0;
    if (strsSize <= 0) return NULL;
    for (int i = 0; i < strsSize; i++) {
        memset(freqMap, 0, sizeof(freqMap));
        create_freq_map(strs[i], freqMap);
        HASH_FIND(hh, map, freqMap, KEYLEN, elem);
        if (!elem) {
            elem = malloc(sizeof(Map));
            memcpy(elem->key, freqMap, KEYLEN);
            elem->listSize = 1;
            elem->list = malloc(sizeof(char**));
            elem->list[0] = strs[i];
            HASH_ADD(hh, map, key, KEYLEN, elem);
        }
        else {
            elem->listSize++;
            elem->list = realloc(elem->list, elem->listSize * sizeof(char**));
            elem->list[elem->listSize - 1] = strs[i];
        }
    }
    *returnSize = HASH_COUNT(map);
    result = malloc(*returnSize * sizeof(char**));
    *returnColumnSizes = malloc(*returnSize * sizeof(int));
    HASH_ITER(hh, map, elem, tmp) {
        (*returnColumnSizes)[mapIndx] = elem->listSize;
        result[mapIndx++] = elem->list;
    }
    HASH_ITER(hh, map, elem, tmp) {
        free(elem);
    }
    return result;
}