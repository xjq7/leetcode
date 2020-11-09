bool backspaceCompare(char * S, char * T){
    unsigned int sLen = strlen(S);
    unsigned int tLen = strlen(T);
    char * sStack = (char *)malloc(sizeof(char)*sLen);
    char * tStack = (char *)malloc(sizeof(char)*tLen);
    int sTop=-1,tTop=-1;
    for(int i=0;i<sLen;i++){
        if(S[i]=='#'){
            if(sTop!=-1)sTop--;
        }else{
            sStack[++sTop]=S[i];
        }
    }
    for(int i=0;i<tLen;i++){
        if(T[i]=='#'){
            if(tTop!=-1)tTop--;
        }else{
            tStack[++tTop]=T[i];
        }
    }
    if(sTop!=tTop){
        free(sStack);
        free(tStack);
        return false;
        
    }
    for(int i=0;i<=sTop;i++){
        if(sStack[i]!=tStack[i]){
            free(sStack);
            free(tStack);
            return false;
        }
    }
    free(sStack);
    free(tStack);
    return true;
}