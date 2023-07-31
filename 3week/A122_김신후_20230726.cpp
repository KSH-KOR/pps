class Solution {
public:
    bool rotateString(string s, string goal) {
        int n= s.length();
        if(s.length() < goal.length()){
            return false;
        }
        string doublestr = s+s;
        for(int i=0; i<n; i++){
            string str= doublestr.substr(i, n);
            if(str == goal){
                return true;
            }
        }
        return false;
    }
};
