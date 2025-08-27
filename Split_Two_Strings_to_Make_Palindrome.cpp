// isPalindrome() :- To verify if a substring within a string is a palindrome.
class Solution {

private:

bool isPalindrome(const  string& s , int left , int right ){    // To verify if a substring within a string is a palindrome.

 while(left < right){
    if(s[left] != s[right])  return false;
        left++;
        right--;
 }
 return true;
}

bool check(const string& a  ,const string& b ){   //To check whether combining the prefix of one string and the suffix of another can form a palindrome.
    int left = 0 ;
    int right = a.size() - 1;
    while(left < right && a[left] == b[right]){
        left++;
        right--;
    }

    return isPalindrome(a ,left , right) || isPalindrome(b , left , right);

  /*
Start with left = 0, right = n - 1
Compare a[left] with b[right]
As long as they match, move inward
When mismatch or pointers cross:
Check if the remaining substring in either a or b is a palindrome
Return true if at least one of those substrings is a palindrome
    */
}


public:
    bool checkPalindromeFormation(string a , string b){
        return check(a , b) || check(b,a);
    }
    
};
