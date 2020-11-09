void reverseString(char* s, int sSize){
    if(!sSize||sSize==1)return;
    int i=0,tmp;
    while (i<(sSize/2)) {
        tmp = *(s+i);
        *(s+i) = *(s+sSize-1-i);
        *(s+sSize-1-i) = tmp;
        i++;
    }
}