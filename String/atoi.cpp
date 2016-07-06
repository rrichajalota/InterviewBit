/*  ATOI
    Implement atoi to convert a string to an integer.
    Example :

    Input : "9 2704"
    Output : 9 
*/

int Solution::atoi(const string &A) {
    
    int num= 0, i=0;
    bool spaces_before_num= false;
    bool is_neg= false;
    
    if(A[0]== ' '){
        spaces_before_num= true;
        ++i; 
    }
    
    while( i < A.length() ){

        if(spaces_before_num == true && A[i]==' ')
            ++i;
            
        else if((spaces_before_num == true || i==0) && (isdigit(A[i]) || A[i]== '-'|| A[i]== '+')){
            spaces_before_num= false;
            
            if(A[i]== '-'){
                is_neg= true;
                ++i;
            }

            else if(A[i]== '+')
                ++i;
                
            while(isdigit(A[i])){
                int digit= A[i]-'0';
                
                if(num <= INT_MAX/10 && (num*10 + digit <= INT_MAX)) // check for overflow
                    num= num*10 + digit;
                    
                else if(num > INT_MAX/10){  // if num > INT_MAX/10, overflow is bound to happen 
                    if(is_neg)
                        return INT_MIN;
                        
                    else return INT_MAX;
                }
                ++i;
            }

            if(is_neg)
                num= -num;

            return num;
        }

        else 
            break;
    }
    return num;
}
