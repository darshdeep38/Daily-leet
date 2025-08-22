\\ Problem Statement :- Leetcode 128 :- Longest Consecutive Sequence :-  Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
\\ You must write an algorithm that runs in O(n) time.
\\ C++ Solution Code: 


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if ( n == 0 ) return 0 ;
        int longest = 1;

        unordered_set<int> st ;
        for( int i = 0 ; i< n; i++){
            st.insert(nums[i]);
        }
        for( auto it : st){
            if( st.find(it - 1) == st.end()){     // If  the previous element is not present in set 
                 int count = 1;
                 int x = it ;        // x is the first element 
                 while( st.find( x + 1) != st.end()){      // found the next consequtive element 
                    x = x + 1;
                    count = count + 1 ;

                 }
                 longest = max( longest , count );

            }
        }
        return longest;
    }
};

