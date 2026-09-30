class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {

        int n = seq.size();
        vector<int> ans(n);

        int depth = 0;

        for (int i = 0; i < n; i++) {

            if (seq[i] == '(') {

                ans[i] = depth % 2;
                depth++;
            }
            else {

                depth--;
                ans[i] = depth % 2;
            }
        }

        return ans;
    }
};