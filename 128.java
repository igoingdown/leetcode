class Solution {
    public int longestConsecutive(int[] nums) {
        int res = 0;
        HashMap<Integer, Integer> m = new HashMap<>();
        for (int n: nums) {
            if (!m.containsKey(n)) {
                int left = m.containsKey(n - 1) ? m.get(n - 1) : 0;
                int right = m.containsKey(n + 1) ? m.get(n + 1) : 0;
                int sum = left + right + 1;
                m.put(n, sum);
                res = Math.max(res, sum);
                m.put(n - left, sum);
                m.put(n + right, sum);
            }
        }
        return res;
    }
}