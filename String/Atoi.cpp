//Atoi O(2*n) | Iterative | codestudio
int atoi(string str) {
    string purestr = ""; int sign=0, i=0;
    if(str[0]=='-'){ sign = 1; i++;}
    else if(str[0]=='+'){i++;}
    for(; i<str.length(); i++){
        if(str[i]>='0'&&str[i]<='9')
            purestr+=str[i];
    }
    int res = 0;
    int power = pow(10, purestr.length()-1);
    for(int j=0; j<purestr.length(); j++){
        res += (purestr[j]-'0')*power;
        power /= 10;
    }
    return sign?-res: res;
}