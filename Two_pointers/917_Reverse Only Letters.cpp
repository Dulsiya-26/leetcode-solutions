class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n=s.length();
        int left=0;
        int right=n-1;
        while(left<right){
            if(!isalpha(s[left])){
              left++;
            }
            else if(!isalpha(s[right])){
                right--;
            }
            else{
                swap(s[left],s[right]);
                left++;
                right--;
            }
        }
       return s;
        
    }
};