class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int mid;
        int hours;
        int answer = right;

        while (left <= right) {
            mid = left + (right - left) / 2;
            hours = 0;

            for (int p : piles)
                hours += (p + mid - 1) / mid;

            if (hours <= h) {
                answer = mid;
                right = mid - 1;
            } else
                left = mid + 1;
        }

        return answer;
    }
};
