import java.util.Arrays;

class Solution {
    private boolean canPlace(int[] stalls, int cows, int gap) {
        int placed = 1;
        int lastPos = stalls[0];
        for (int i = 1; i < stalls.length; i++) {
            if (stalls[i] - lastPos >= gap) {
                placed++;
                lastPos = stalls[i];
                if (placed >= cows) return true;
            }
        }
        return false;
    }

    public int aggressiveCows(int[] stalls, int cows) {
        Arrays.sort(stalls);
        int low = 0;
        int high = stalls[stalls.length - 1] - stalls[0];
        int result = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canPlace(stalls, cows, mid)) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] stalls = {1, 2, 4, 8, 9};
        int cows = 3;
        System.out.println("Maximum minimum distance: " + sol.aggressiveCows(stalls, cows));
    }
}
