int* cal_next(char* str,int len){
    int *next =(int*)malloc(sizeof(int)*len);
    for(int i=0;i<len;i++){
        next[i]=0;
    }
    next[0]=-1;
    int i=0,j=1;
    while (j<len) {
        if(i==-1||str[i]==str[j]){
            i++;
            j++;
            if(j<len)next[j]=i;
        }else{
            i=next[i];
        }
    }
    return next;
}

int strStr(char * haystack, char * needle){
    int hLen,nLen;
    hLen = strlen(haystack);
    nLen = strlen(needle);
    if(!nLen)return 0;
    if(!hLen)return -1;
    int *next_;
    next_ = cal_next(needle,nLen);
    int i=0,j=0;
    
    while (i<hLen) {
        if(j==-1||haystack[i]==needle[j]){
            i++;
            j++;
            if(j==nLen)return i-j;
        }else{
            j=next_[j];
        }
    }
    return -1;
}