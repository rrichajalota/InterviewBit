/*  Nearest Smallest Element

    Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.
    More formally,
    G[i] for an element A[i] = an element A[j] such that 
        j is maximum possible AND 
        j < i AND
        A[j] < A[i]
    Elements for which no smaller element exist, consider next smaller element as -1.

    Example:

    Input : A : [4, 5, 2, 10]
    Return : [-1, 4, -1, 2]

    Example 2:

    Input : A : [3, 2, 1]
    Return : [-1, -1, -1]
*/

vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> small;
    
    for(int i =0; i < A.size(); i++){
        int temp = A[i];
        
        if(small.empty())
            A[i]= -1;
            
        else if(small.top() >= temp){
            
            while(!small.empty() && small.top() >= temp){   //look for a smaller element in the stack
                small.pop();
            }
            
            if(small.empty())                   //if smaller element not found
                A[i]= -1;
                
            else A[i]= small.top();             //if smaller element is found 
        }
        else                 //if small.top() < temp 
            A[i]= small.top();
        
        small.push(temp);   //push current element onto the stack
    }
    return A;
}
