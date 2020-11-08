bool canThreePartsEqualSum(int* A, int ASize){
    int sum = 0;
    for(int i=0;i<ASize;i++)sum+=*(A+i);
    if(sum%3)return false;
    int avg = sum/3;
    int part=0,count=0;
    for(int i=0;i<ASize;i++){
        part+=A[i];
        if(part==avg){
            count++;
            part=0;
        }
    }
    return count>=3;
}