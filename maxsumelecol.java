import java.util.*;

class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int r = sc.nextInt();
        int c = sc.nextInt();

        int[][] grid = new int[r][c];
        long[][] dp = new long[r][c];

        for (int row = 0; row < r; row++) {
            for (int col = 0; col < c; col++) {
                grid[row][col] = sc.nextInt();

                if (col == 0) {
                    dp[row][col] = grid[row][col];
                }
            }
        }

        for (int col = 1; col < c; col++) {

            long[] fsmax = getFSMax(dp, col - 1, r);

            for (int row = 0; row < r; row++) {

                dp[row][col] = grid[row][col] + (dp[row][col - 1] == fsmax[0]? fsmax[1]: fsmax[0]);
            }
        }

        System.out.println(getFSMax(dp, c - 1, r)[0]);
    }

    private static long[] getFSMax(long[][] dp, int col, int r) {

        long fmax = Math.max(dp[0][col], dp[1][col]);
        long smax = Math.min(dp[0][col], dp[1][col]);

        for (int row = 2; row < r; row++) {

            if (dp[row][col] > fmax) {
                smax = fmax;
                fmax = dp[row][col];
            } else if (dp[row][col] > smax) {
                smax = dp[row][col];
            }
        }

        return new long[]{fmax, smax};
    }
}