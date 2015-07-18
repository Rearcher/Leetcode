class Solution {
public:
	TreeNode* build(vector<int>& nums, int left, int right) {
		if(left > right) return nullptr;
		int mid = (left+right)/2;
		TreeNode* node = new TreeNode(nums[mid]);
		node->left = build(nums, left, mid-1);
		node->right = build(nums, mid+1, right);
		return node;
	}
	
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return build(nums, 0, nums.size()-1);
	}
};
