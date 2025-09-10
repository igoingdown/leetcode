class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> q = new PriorityQueue<>(k, new Comparator<Integer> () {
            public int compare(Integer a , Integer b) {
                return a - b;
            }
        });
        for (int i = 0; i < nums.length; i++) {
            if (i < k) q.offer(nums[i]);
            else {
                if (nums[i] > q.peek()) {
                    q.poll();
                    q.offer(nums[i]);
                }
            }
        }
        return q.peek();
    }
}