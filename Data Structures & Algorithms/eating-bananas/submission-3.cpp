class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long maxPile = ranges::max(piles);
        int size = piles.size();

        if (h == size) {
            return maxPile;
        }

        long long currH = 0;
        long long left = 1;
        long long right = maxPile;
        long long currRate = 1;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            currH = calculateHours(piles, mid, size);

            if (currH == h) {
                currRate = mid;
                right = mid - 1;
            }
            else if (currH > h) {
                left = mid + 1;
            }
            else {
                currRate = mid;
                right = mid - 1;
            }
        }

        return static_cast<int>(currRate);
    }

    long long calculateHours(
        vector<int>& piles,
        long long rate,
        int size
    ) {
        long long hours = 0;

        for (int i = 0; i < size; i++) {
            hours += (static_cast<long long>(piles[i]) + rate - 1) / rate;
        }

        return hours;
    }
};