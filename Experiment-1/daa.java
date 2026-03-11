public class daa {
    static int operation = 0;
    static int complexRec(int n, int depth) {
        if (n <= 2) {
            return depth;
        }

        int p = n;
        while (p > 0) {
            int[] temp = new int[n];
            for (int i = 0; i < n; i++) {
                temp[i] = i ^ p;
                operation++;
            }
            p >>= 1;
            operation++;
        }

        int[] small = new int[n];
        for (int i = 0; i < n; i++) {
            small[i] = i * i;
            operation++;
        }

        reverseArray(small);

        int d1 = complexRec(n / 2, depth + 1);
        int d2 = complexRec(n / 2, depth + 1);
        int d3 = complexRec(n / 2, depth + 1);

        return Math.max(depth, Math.max(d1, Math.max(d2, d3)));
    }
    private static void reverseArray(int[] arr) {
        int left = 0, right = arr.length - 1;
        while (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
            operation++;
        }
    }
    public static void main(String[] args) {
        int finalDepth = complexRec(16, 0);
        System.out.println("Final max depth = " + finalDepth);
        System.out.println("Total operations = " + operation);
        //Final max depth=3
        //Total operations=442
    }
}