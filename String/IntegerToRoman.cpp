/*  INTEGER TO ROMAN

    Given an integer, convert it to a roman numeral, and return a string corresponding to its roman numeral version
    Input is guaranteed to be within the range from 1 to 3999.

    Example :
    
    Input : 5
    Return : "V"

    Input : 14
    Return : "XIV"

     Note : This question has a lot of scope of clarification from the interviewer. Please take a moment to think of all the needed clarifications and see the expected response using “See Expected Output” For the purpose of this question, https://projecteuler.net/about=roman_numerals has very detailed explanations. 
*/

string Solution::intToRoman(int A) {

    string rom= "";

    int len = log10(A) + 1;
    int divisor = int(pow(10, len-1));

    map<int, std::string> roman= {{1,"I"}, {5,"V"}, {10,"X"}, {50,"L"}, {100,"C"}, {500,"D"}, {1000,"M"}};
    
    while(A){

        int num= A/divisor;

        if(num==5)
            rom += roman[num*divisor];

        else if(num == 4 || num == 9){
            rom += roman[divisor];
            rom += roman[(num+1)* divisor];
        }

        else if(num < 4){
            while(num){
                rom += roman[divisor];
                --num;
            }
        }

        else if(num > 5 && num < 9){
            rom += roman[5*divisor];
            while(num> 5){
                rom += roman[divisor];
                --num;
            }
        }

        A = A % divisor;
        divisor /= 10;
    }

    return rom;
}
