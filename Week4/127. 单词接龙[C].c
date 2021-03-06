//queue + BFS
typedef struct queue{
    int loc;
    int step;
    struct queue *next;
}queue;

struct queue *head = NULL;
struct queue *tail = NULL;

void pop(){
    if(head){
        struct queue *temp = head;
        head = head->next;
        free(temp);
    }
}

void push (struct queue * q){
    if(!head){
        head = q;
        tail = q;
        head -> next = NULL;
        tail -> next = NULL;
    }
    else{
        tail-> next = q;
        tail = tail->next;
        tail-> next = NULL;
    }
}

void create_push(int loc, int step){
    struct queue * new = malloc(sizeof(queue));
    new->loc = loc;
    new->step = step;
    push(new);
}

int bfs(char* b, char* e, char ** wordList, char* visited, int size){
    if(!strcmp(b,e))
        return head->step;
    
    int leng = strlen(b);
    int i, j;
    //char* temp1 = malloc(sizeof(char)*leng+1);
    //char* temp2 = malloc(sizeof(char)*leng+1);
    int curr = head->step;
    

    for(i=0;i<size;i++){
        if(visited[i])
            continue;
        int diff =0;
        
        for(j=0;j<leng;j++){
            if(b[j] != wordList[i][j]){
                diff++;
                if(diff>1)
                    break;
            }
        }
        if(diff==1){
            create_push(i, curr+1);
            visited[i] = 1;
        }
        //this is too slow 
/*        for(j=0;j<leng;j++){
            strncpy(temp1,b,leng);
            strncpy(temp2,wordList[i],leng);
            temp1[j] = ' ';
            temp2[j] = ' ';
            temp1[leng] = '\0';
            temp2[leng] = '\0';
            if(!strncmp(temp1,temp2,leng)){
                printf("%d %s\n", head->step, wordList[i]);
                create_push(i, curr+1);
                visited[i] = 1;
            }
        }*/
    }
    int ret = 0;
    if(head->next){
        pop();
        ret = bfs(wordList[head->loc], e, wordList, visited, size);        
    }
    else{
        return 0;
    }
    return ret;
}

int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize){
    int visited[wordListSize];
    memset(visited, 0, wordListSize*sizeof(visited[0]));
    
    int ret = 0;
    create_push(-1,1);
    ret = bfs(beginWord, endWord, wordList, visited, wordListSize);
    while(head)
        pop();
    
    return ret;
}