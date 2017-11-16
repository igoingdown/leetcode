import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class BestMeetingPoint {
    public static void main(String[] args) {
        int[][] grid = {
                {1, 0, 0, 0, 1},
                {0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0}};
        System.out.println(minTotalDistance(grid));
    }

    private static int minTotalDistance(int[][] grid) {
        List<Integer> iPos = new ArrayList<>();
        List<Integer> jPos = new ArrayList<>();
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 1) {
                    iPos.add(i);
                    jPos.add(j);
                }
            }
        }
        Collections.sort(iPos);
        Collections.sort(jPos);
        int sum = 0;
        int start = 0, end = iPos.size() - 1;
        while (start < end) {
            sum += iPos.get(end) - iPos.get(start);
            sum += jPos.get(end) - jPos.get(start);
            end--;
            start++;
        }
        return sum;
    }
}