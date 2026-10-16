class Solution {
public:
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right)
            return NULL;

        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);

        node->left = helper(nums, left, mid - 1);
        node->right = helper(nums, mid + 1, right);

        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())
            return NULL;

        return helper(nums, 0, nums.size() - 1);
    }
};