class Solution {
    private LinkedList<String> path = new LinkedList<>();
    private HashMap<String, PriorityQueue<String>> m = new HashMap<>();
    public List<String> findItinerary(String[][] tickets) {
        for (String[] pair : tickets) {
            m.putIfAbsent(pair[0], new PriorityQueue<>());
            m.get(pair[0]).add(pair[1]);
        }
        dfs("JFK");
        return path;
    }
    private void dfs(String departure) {
        PriorityQueue<String> q = m.get(departure);
        while (q != null && !q.isEmpty()) {
            dfs(q.poll());
        }
        path.addFirst(departure);
    }
}