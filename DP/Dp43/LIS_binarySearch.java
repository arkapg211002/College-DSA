import java.util.*;
public class Main {
    public static int getAns(int[] arr, int n, int ind, int prev_index, List<List<Integer>> dp) {
        // base condition
        if (ind == n)
            return 0;
        if (dp.get(ind).get(prev_index + 1) != -1)
            return dp.get(ind).get(prev_index + 1);
        int notTake = 0 + getAns(arr, n, ind + 1, prev_index, dp);
        int take = 0;
        if (prev_index == -1 || arr[ind] > arr[prev_index]) {
            take = 1 + getAns(arr, n, ind + 1, ind, dp);
        }
        return dp.get(ind).set(prev_index + 1, Math.max(notTake, take));
    }
    public static int longestIncreasingSubsequence(int[] arr, int n) {
        List<Integer> temp = new ArrayList<>();
        temp.add(arr[0]);
        int len = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] > temp.get(temp.size() - 1)) {
                // arr[i] > the last element of temp array
                temp.add(arr[i]);
                len++;
            } else {
                // replacement step
                int ind = Collections.binarySearch(temp, arr[i]);
                if (ind < 0)
                    ind = -ind - 1;
                temp.set(ind, arr[i]);
            }
        }
        return len;
    }
    public static void main(String[] args) {
        int[] arr = { 10, 9, 2, 5, 3, 7, 101, 18 };
        int n = arr.length;
        List<List<Integer>> dp = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            List<Integer> row = new ArrayList<>(Collections.nCopies(n + 1, -1));
            dp.add(row);
        }
        System.out.println("The length of the longest increasing subsequence is " + longestIncreasingSubsequence(arr, n));
    }
}
