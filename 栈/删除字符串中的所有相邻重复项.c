char * removeDuplicates(char * S){
    int len = strlen(S);
    int top=-1;
    for(int i=0;i<len;i++){
        if(top!=-1&&S[i]==S[top]){
            top--;
        }else{
            S[++top] = S[i];
        }
    }
    S[++top] = '\0';
    return S;
}