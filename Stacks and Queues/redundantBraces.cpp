/*  REDUNDANT BRACES
    Write a program to validate if the input string has redundant braces?
    Return 0/1 
     0 -> NO 1 -> YES 
    Input will be always a valid expression
    and operators allowed are only + , * , - , /
    Example:
    ((a+b)) has redundant braces so answer will be 1
    (a + (a + b)) doesn't have have any redundant braces so answer will be 0
*/

/*  We maintain a stack by repeatedly removing sub expressions. As soon as a closing brace is 
    encountered, we start popping the operators from the stack till we reach the corresponding
    opening brace. If the top element is the opening brace itself, we know it must be a duplicate brace.
    (considering the case (a) or ((a+b)), after removing the sub-expression (a+b) we are left with only ()
    which are duplicate braces.)
    Note that we just push the operators on the stack. This will keep the extra space occupied by the stack
    minimum. Unless the question requires checking of the subexpressions to be valid, we can go by this approach. In
    our case, an expression like (a*) will also be valid. If we want to check if the expression (along with it's operands) is valid, push operands 
    as well.
*/

int Solution::braces(string A) {
    stack<char> symbols;
    
    for(int i= 0; i < A.length(); i++){
        
        if (A[i]=='(' || A[i]== '{' || A[i]== '[')
                symbols.push(A[i]);
    
        else if(A[i]=='+' || A[i]== '-' || A[i]== '*'|| A[i]== '/'){  // if the exp. is just a+b, no need to push + onto stack
            if(!symbols.empty())
                symbols.push(A[i]);
        }
            
        else if(A[i]==')'|| A[i]== '}' || A[i]== ']'){
            
            if(symbols.top()=='(' || symbols.top()=='{'|| symbols.top()=='[')
                return 1;
                
            else if(A[i]== ')'){
                while(symbols.top() != '(')
                    symbols.pop();
                symbols.pop();
            }
            
            else if(A[i]== ']'){
                while(symbols.top() != '[')
                    symbols.pop();
                symbols.pop();
            }
            
            else if(A[i]== '}'){
                while(symbols.top() != '{')
                    symbols.pop();
                symbols.pop();
            }
        }
    }
    
    return !symbols.empty(); //if stack is empty means no duplicates exist, return 0
}
