import java.util.*;

class Solution {
    private long hoursNeeded(int[] piles, int speed) {
        long hours = 0;
        for (int bananas : piles) {
            hours += (bananas + speed - 1) / speed;  
        }
        return hours;
    }

    public int minEatingSpeed(int[] piles, int h) {
        int maxPile = Arrays.stream(piles).max().getAsInt();
        int low = 1, high = maxPile, ans = maxPile;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (hoursNeeded(piles, mid) <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    // Example usage
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] piles = {3, 6, 7, 11};
        int h = 8;
        System.out.println("Minimum eating speed: " + sol.minEatingSpeed(piles, h));
    }
}