class Solution {
public:
    vector<vector<int>> res;

    void backtrack(vector<int>& candidates, int target, vector<int>& temp, int start) {
        if (target == 0) {
            res.push_back(temp);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // Stop exploring further if number exceeds target
            if (candidates[i] > target)
                break;

            temp.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], temp, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        backtrack(candidates, target, temp, 0);
        return res;
    }
};
