import java.util.Comparator;
import java.util.PriorityQueue;

public class SlidingWindowMaximum {
    public static void main(String[] args) {
        int[] nums = {1, 2, 4, 0, 6};
        for (int i : maxSlidingWindow(nums, 3)) {
            System.out.println(i);
        }
    }

    public static int[] maxSlidingWindow(int[] nums, int k) {
        if (nums == null || nums.length == 0) return nums;
        PriorityQueue<Integer> q = new PriorityQueue<>(k, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2 - o1;
            }
        });
        int[] res = new int[nums.length - k + 1];
        for (int i = 0; i < nums.length; i++) {
            if (i >= k) {
                q.remove(nums[i - k]);
            }
            q.offer(nums[i]);
            if (i >= k - 1) {
                res[i + 1 - k] = q.peek();
            }
        }
        return res;
    }
}
