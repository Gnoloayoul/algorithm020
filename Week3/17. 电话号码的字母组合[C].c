void procedure(char **res, char *digits, int index, char map[8][5], int *top, char *tmp)
{  
    int digit = digits[index] - '0' - 2;
    if(digits[index] == 0)
    {  
        res[*top] = (char *)malloc((index+1) * sizeof(char));
        strcpy(res[*top], tmp);
        (*top)++;
        return;  
    }
    for(int i=0; map[digit][i]; i++)
    {  
        tmp[index] = map[digit][i];
        procedure(res, digits, index+1, map, top, tmp);  
    }  
}  
char** letterCombinations(char* digits, int* returnSize)
{  
     char map[8][5]={"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};  
     int total_num=1, length=0, top=0;  
     while(digits[length])
     {  
         if(digits[length]=='7' || digits[length]=='9') 
             total_num *= 4;
         else
             total_num *= 3;
         length++;  
     }
     char **res, *tmp;  
     res = (char **)malloc(total_num * sizeof(char *));
     tmp = (char *)malloc((length+1) * sizeof(char));
     tmp[length] = 0;
     if(length==0){  
         *returnSize=0;  
         return res;  
     }
     procedure(res, digits, 0, map, &top, tmp);
     *returnSize = top;
     free(tmp);
     return res;  
}  