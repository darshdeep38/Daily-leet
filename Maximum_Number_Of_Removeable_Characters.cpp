class Solution {
public:
    bool isSubsequence(string &s, string &p, vector<int>& removable, int k) {
        int n = s.size(), m = p.size();
        vector<bool> removed(n, false);

        // Mark first k indices as removed
        for (int i = 0; i < k; i++) {
            removed[removable[i]] = true;
        }

        int j = 0; // pointer for p
        for (int i = 0; i < n && j < m; i++) {
            if (!removed[i] && s[i] == p[j]) {
                j++;
            }
        }

        return j == m;
    }

    int maximumRemovals(string s, string p, vector<int>& removable) {
        int left = 0, right = removable.size(), ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (isSubsequence(s, p, removable, mid)) {
                ans = mid;        // can remove mid characters
                left = mid + 1;   // try more removals
            } else {
                right = mid - 1;  // try fewer removals
            }
        }

        return ans;
    }
};
