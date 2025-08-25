// Problem Statement :-You are playing a game involving a circular array of non-zero integers nums. Each nums[i] denotes the number of indices forward/backward you must move if you are located at index i:

// If nums[i] is positive, move nums[i] steps forward, and
//If nums[i] is negative, move nums[i] steps backward.
//Since the array is circular, you may assume that moving forward from the last element puts you on the first element, and moving backwards from the first element puts you on the last element.
//A cycle in the array consists of a sequence of indices seq of length k where:
//Following the movement rules above results in the repeating index sequence seq[0] -> seq[1] -> ... -> seq[k - 1] -> seq[0] -> ...
//Every nums[seq[j]] is either all positive or all negative.
//k > 1
//Return true if there is a cycle in nums, or false otherwise.


// Here is the C++ code:
class Solution {
private:
    int getNext(int current, const vector<int>& nums) {
        int n = nums.size();
        return ((current + nums[current]) % n + n) % n;
    }

public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            // Skip if already visited
            if (nums[i] == 0) {
                continue;
            }

            int slow = i;
            int fast = i;
            int direction = nums[i] > 0; // True for positive, False for negative

            while (true) {
                // Move slow pointer
                slow = getNext(slow, nums);
                if ((nums[slow] > 0) != direction) break; // Direction change
                
                // Move fast pointer
                fast = getNext(fast, nums);
                if ((nums[fast] > 0) != direction) break; // Direction change
                fast = getNext(fast, nums);
                if ((nums[fast] > 0) != direction) break; // Direction change
                
                // Check for a cycle of length 1 (slow moves and comes back to original spot)
                if (slow == getNext(slow, nums)) {
                    break;
                }

                if (slow == fast) {
                    return true;
                }
            }
            
            // Mark the path as invalid by setting elements to 0
            int current = i;
            while (nums[current] != 0 && (nums[current] > 0) == direction) {
                int next = getNext(current, nums);
                nums[current] = 0;
                current = next;
            }
        }
        return false;
    }
};

//
//equivalent java code
//


import java.util.*;

class Solution {
    private int getNext(int current, int[] nums) {
        int n = nums.length;
        return ((current + nums[current]) % n + n) % n;
    }

    public boolean circularArrayLoop(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            // Skip if already visited
            if (nums[i] == 0) {
                continue;
            }

            int slow = i;
            int fast = i;
            boolean direction = nums[i] > 0; // True for positive, False for negative

            while (true) {
                // Move slow pointer
                slow = getNext(slow, nums);
                if ((nums[slow] > 0) != direction) break; // Direction change
                
                // Move fast pointer
                fast = getNext(fast, nums);
                if ((nums[fast] > 0) != direction) break; // Direction change
                fast = getNext(fast, nums);
                if ((nums[fast] > 0) != direction) break; // Direction change

                if (slow == getNext(slow, nums)) {
                    break;
                }

                if (slow == fast) {
                    return true;
                }
            }

            int current = i;
            while (nums[current] != 0 && (nums[current] > 0) == direction) {
                int next = getNext(current, nums);
                nums[current] = 0;
                current = next;
            }
        }
        return false;
    }
}


 
