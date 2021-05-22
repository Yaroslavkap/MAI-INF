int myAtoi(char * s){
   
        int i = 0;
        int zn = 1;
        int max = 2147483647;

        while(s[i] == ' '){
            i++;
        }

        

        if(s[i] == '+'){
            zn = 1;
            i++;
        } else if(s[i] == '-') {
            zn = -1;
            i++;
        }
            

        if(s[i] - '0' < 0 || s[i] - '0' > 9){
            return 0;
        }

        int num = 0;

        while(s[i] >= '0' && s[i] <= '9'){
            if(num > max/10 || (num == max/10 && s[i] - '0' > 7)){
                if (zn == 1){
                    return zn * max;
                } else {
                    return zn * max - 1;
                }   
            }

            num = num*10 + (s[i] - '0');
            i++;
        }

        if (num <= max) {
            return num * zn;
    } else if(zn == 1) {
        return zn * max;
    } else {
        return zn * max - 1;
    }
    
}
