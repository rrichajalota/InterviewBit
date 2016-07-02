/*  VALID IP ADDRESSES
    Given a string containing only digits, restore it by returning all possible valid IP address combinations.
    A valid IP address must be in the form of A.B.C.D, where A,B,C and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.

    Example:
    Given “25525511135”,
    return [“255.255.11.135”, “255.255.111.35”]. (Make sure the returned strings are sorted in order)
*/


bool isvalid(string s);

vector<string> Solution::restoreIpAddresses(string A) {
    vector<string> ans;
    for(int i=1; i < 4; i++){
        string s1= A.substr(0,i);
        if(isvalid(s1)){
            for(int j= 1; i+j < A.size() && j < 4; j++){
                string s2= A.substr(i,j);
                if(isvalid(s2)){
                    for(int k = 1; i+j+k < A.size() && k< 4 ; k++){
                        string s3= A.substr(i+j,k);
                        string s4= A.substr(i+j+k);
                        if(isvalid(s3) && isvalid(s4)){
                            ans.push_back(s1+'.'+s2+'.'+s3+'.'+s4);
                        }
                    }
                }
            }
        }
    }
    return ans;
}

bool isvalid(string s){
    if(s.size() > 3)
        return false;
        
    if(s.front()=='0'&& s.size() > 1)
        return false;
    
    int num= stoi(s);
    
    return (num <= 255 && num >= 0);
}
