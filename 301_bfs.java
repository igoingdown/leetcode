class Solution {
    public List<String> removeInvalidParentheses(String s) {
        List<String> res = new ArrayList<>();
        int max = 0;
        Set<String> checked = new HashSet<>();
        Queue<String> q = new LinkedList<>();
        boolean found = false;
        q.offer(s);
        while (!q.isEmpty()) {
            String cur = q.poll();
            if (isValid(cur)) {
                found = true;
                if (cur.length() >= max && !res.contains(cur)) {
                    max = cur.length();
                    res.add(cur);
                }
            }
            if (found) continue;
            for (int i = 0; i < cur.length(); i++) {
                String sub1 = cur.substring(0, i);
                String sub2 = cur.substring(i + 1, cur.length());
                String next = sub1.concat(sub2);
                if (!checked.contains(next)) {
                    q.offer(next);
                    checked.add(next);
                }
            }
        }
        return res;
        
    }
    
    private boolean isValid(String s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') count++;
            else if (s.charAt(i) == ')') {
                if (count == 0) return false;
                count--;
            }
        }
        return count == 0;
    }
}