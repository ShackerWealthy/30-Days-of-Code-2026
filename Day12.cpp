class Solution {
public:
    int findBound(vector<int>& nums, int target, bool isFirst) {
        int low = 0;
        int high = nums.size() - 1;
        int bound = -1;
        int mid;

        while (low <= high) {
            mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                bound = mid;
                if (isFirst)
                    high = mid - 1;
                else
                    low = mid + 1; 
            } else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return bound;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int start = findBound(nums, target, true);
        int end = findBound(nums, target, false);
        return {start, end};
    }
};
