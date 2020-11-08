int calPoints(char ** ops, int opsSize){
    if(!opsSize)return 0;
    int score=0,tmp;
    int stack[opsSize];
    int top=-1;
  
    for(int i=0;i<opsSize;i++){
        tmp=stack[top];
        if(isalpha(ops[i][0])){
            if(ops[i][0]=='C'){
                score-=stack[top--];
            }else{
                score+=tmp*2;
                stack[++top]=tmp*2;
            }
        }else if((ops[i][0]>='0'&&ops[i][0]<='9')||ops[i][0]=='-'){
            score+=atoi(&ops[i][0]);
            stack[++top]= atoi(&ops[i][0]);
        }else{
            score+=tmp+stack[top-1];
            stack[top+1]=tmp+stack[top-1];
            top++;
        }
    }
    return score;
}