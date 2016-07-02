/*  ZIGZAG STRING
    The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

    P.......A........H.......N
    ..A..P....L....S....I...I....G
    ....Y.........I........R
    And then read line by line: PAHNAPLSIIGYIR
    Write the code that will take a string and make this conversion given a number of rows:

    string convert(string text, int nRows);
    convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
    **Example 2 : **
    ABCD, 2 can be written as

    A....C
    ...B....D
    and hence the answer would be ACBD.

*/
string Solution::convert(string A, int B) {
    vector<string> str(B);
    string ans= "";
    int i=0, j=0, k=0;
    
    while( i < A.length()){
        
        while(j < B && i < A.length()){     // come down from row 0 to B-1
            str[j].push_back(A[i]);
            ++j, ++i;
        }
        
        j -= 2;
        while(j > 0 && i < A.length()){     //go up from B-2 to 1 
            str[j].push_back(A[i]);
            --j, ++i;
        }
        j=0, ++k;
    }
    j=0;
    while(j < B){                           // finally concatenate
        ans += str[j];
        ++j;
    }
    return ans;
}
