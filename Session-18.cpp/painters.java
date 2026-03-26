
public class painters {
    private boolean isPossible(int[] boards, int k, long maxLen) {
        long sum = 0;
        int painters = 1;
        for (int x : boards) {
            if (sum + x <= maxLen) {
                sum += x;
            } else {
                painters++;
                sum = x;
                if (painters > k) return false;
            }
        }
        return true;
    }

    public int minTime(int[] boards, int k) {
        long left = 0, right = 0;
        for (int x : boards) {
            left = Math.max(left, (long)x);
            right += x;
        }

        long ans = right;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            if (isPossible(boards, k, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return (int)ans;
    }

    public static void main(String[] args) {
        painters sol = new painters();
        int[] boards = {10, 20, 30, 40};
        int k = 2;
        System.out.println(sol.minTime(boards, k));
    }
}
