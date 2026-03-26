
public class lowerBound {
    public static int findLowerBound(int[] nums, int val) {
        int start = 0;
        int end = nums.length - 1;
        int res = nums.length;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] >= val) {
                res = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int[] nums = {0, 1, 1, 2, 3, 4, 5};
        int ans = findLowerBound(nums, 1);
        System.out.println(ans);
    }
}
