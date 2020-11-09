bool isPalindrome(char * s){
    unsigned long len = strlen(s);
    if(!len){
        return true;
    }
    int i=0,j=--len;
    while(i<j){
        if(!isalnum(s[i])){
            i++;
            continue;
        }
        if(!isalnum(s[j])){
            j--;
            continue;
        }
           
        if(isalpha(s[i])&&isalpha(s[j])){
            if((islower(s[i])&&islower(s[j]))||(isupper(s[i])&&isupper(s[j]))){
                if(s[i]!=s[j])return false;
            }else if(s[i]<s[j]){
                if((s[j]-32)!=s[i])return false;
            }else{
                if((s[i]-32)!=s[j])return false;
            }
        }else{
            if(s[i]!=s[j])return false;
        }
        j--;
        i++;
    }
    return true;
}