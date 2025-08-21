// This is the solution of Leetcode problem no. 39 where we are "Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of
//candidates where the chosen numbers sum to target. You may return the combinations in any order.

// Here is the C++ code for the Solution 
class Solution {
public:
void backtrack(int start , vector<int>& candidates , int target , vector<int>& path , vector<vector<int>>& result){

if(target == 0 ){
    result.push_back(path);
    return ;
}
if(target < 0 ) return ;

for( int i = start ; i< candidates.size() ; ++i){
path.push_back(candidates[i]);
backtrack( i , candidates , target - candidates[i] , path , result );
path.pop_back();
}

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result ; 
        vector<int> path;
        backtrack(0 , candidates , target , path , result );
        return result ;
    }
};


/* Here i have used the logic of Backtracking to solve this problem 
backtrack(i, candidates, target - candidates[i], path, result);

i: allows us to reuse the same number.
target - candidates[i]: reduces the target by the value just chosen.
path: the current partial combination.
result: holds all the valid combinations found so far.
This recursive call explores deeper combinations starting from the current number.
  /*



