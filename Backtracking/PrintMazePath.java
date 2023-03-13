
import java.util.*;

public class MazePath {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();
        ArrayList<String> paths = getMazePaths(1, 1, n, m);
        System.out.println(paths);
    }

    public static ArrayList<String> getMazePaths(int sr, int sc, int dr, int dc) {
        if (sr == dr && sc == dc) {
            ArrayList<String> baseResult = new ArrayList<>();
            baseResult.add("");
            return baseResult;
        }
        ArrayList<String> myResult = new ArrayList<>();
        if (sc + 1 <= dc) {
            ArrayList<String> recResult = getMazePaths(sr, sc + 1, dr, dc);
            for (String s : recResult) {
                myResult.add("h" + s);
            }
        }
        if (sr + 1 <= dr) {
            ArrayList<String> recResult = getMazePaths(sr + 1, sc, dr, dc);
            for (String s : recResult) {
                myResult.add("v" + s);
            }
        }
        return myResult;
    }
}
