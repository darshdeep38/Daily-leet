class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;

        unordered_set<string> beginSet, endSet, visited;
        beginSet.insert(beginWord);
        endSet.insert(endWord);

        int steps = 1;

        while (!beginSet.empty() && !endSet.empty()) {

            // Always expand the smaller set for optimization
            if (beginSet.size() > endSet.size()) {
                swap(beginSet, endSet);
            }

            unordered_set<string> nextSet;

            for (auto word : beginSet) {
                string temp = word;

                for (int i = 0; i < temp.size(); i++) {
                    char original = temp[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        temp[i] = c;
                        if (!dict.count(temp)) continue;

                        // If connection found
                        if (endSet.count(temp)) {
                            return steps + 1;
                        }

                        // If not visited, add to next level
                        if (!visited.count(temp)) {
                            visited.insert(temp);
                            nextSet.insert(temp);
                        }
                    }
                    temp[i] = original;
                }
            }

            beginSet = nextSet;
            steps++;
        }

        return 0;
    }
};
