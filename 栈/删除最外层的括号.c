char * removeOuterParentheses(char * S){
    int len = strlen(S);
    char stack[len+1];
    //栈顶
    int top=-1;
    //结果栈栈顶
    int j=0;
    //主要逻辑
    for(int i=0;i<len;i++){
        if(S[i]=='('){
            stack[++top]=S[i];
            if(top!=0)S[j++]=S[i];
        }else{
            if(top!=0)S[j++] = S[i];
            top--;
        }
    }
    //对结果做处理
    S[j] ='\0';
    return S;
}