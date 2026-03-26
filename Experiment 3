import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        char[] attendance = new char[n];

        for (int i = 0; i < n; i++) {
            attendance[i] = sc.next().charAt(0);
        }

        Map<Integer, Integer> mp = new HashMap<>();
        int sum = 0, m = 0;

        mp.put(0, -1);

        for (int i = 0; i < n; i++) {
            if (attendance[i] == 'P') {
                sum += 1;
            } else {
                sum -= 1;
            }

            if (mp.containsKey(sum)) {
                m = Math.max(m, i - mp.get(sum));
            } else {
                mp.put(sum, i);
            }
        }

        System.out.println(m);
        sc.close();
    }
}
