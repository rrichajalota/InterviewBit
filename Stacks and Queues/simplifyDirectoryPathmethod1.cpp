/*  Simplify Directory Path
    Given an absolute path for a file (Unix-style), simplify it.

    Examples:

    path = "/home/", => "/home"
    path = "/a/./b/../../c/", => "/c"
    Note that absolute path always begin with ‘/’ ( root directory )
    Path will not have whitespace characters.
*/ 

string Solution::simplifyPath(string A) {
    
    string res="";
    stack<string> path;
    int i= 0;
    
    while(A[i]=='/'){           //multiple slashes not allowed, skip them
        ++i;
    }
    
    while(i < A.length()){          
    
        string str;
        
        while(A[i]== '/')           //skip multiple slashes
            ++i;
            
        int pos= A.find('/',i);     //find the first occurence of '/' in the remaining string 
        
        if(pos== string::npos)      //if '/' is not found, the entire remaining string is the substring
            str= A.substr(i);
        
        else
            str= A.substr(i,pos-i);     //else, the string upto '/' is the substring, '/' not included. 
            
            
        if(str==".." && !path.empty()){     
            path.pop();
        }
        
        else if(str!= "." && str!="..")     //if string contains more than 2 dots or other characters, push it on the stack
            path.push(str);
    
        if(pos!= string::npos)              //increment i to 1 position after pos
            i= pos+1;
            
        else break;
    }
    
    while(!path.empty()){                   
        string s= path.top();               
        path.pop();
        res= "/"+s + res;               //add the string from the stack to the resultant string
    }
    
    if(res.length()==0)
        return "/";
        
    return res;
}
