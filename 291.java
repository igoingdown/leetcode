import java.util.HashMap;

public class WordPatternII {
    public static void main(String[] args) {
        String pattern = "aabb";
        String str = "redredbluebune";
        if (wordPattern(pattern, str)) System.out.println("yes");
        else System.out.println("No");
    }

    private static boolean wordPattern(String pattern, String str) {
        HashMap<Character, String> m1 = new HashMap<>();
        HashMap<String, Character> m2 = new HashMap<>();
        return dfs(pattern, str, 0, 0, m1, m2);
    }

    private static boolean dfs(String pattern, String str, int patternStart, int strStart,
                               HashMap<Character, String> m1, HashMap<String, Character> m2) {
        if (patternStart == pattern.length()) {
            return strStart == str.length();
        }
        for (int i = strStart; i < str.length(); i++) {
            String tmp = str.substring(strStart, i + 1);
            if (m1.containsKey(pattern.charAt(patternStart))) {
                if (m2.containsKey(tmp) && m2.get(tmp) == pattern.charAt(patternStart) &&
                        m1.get(pattern.charAt(patternStart)).equals(tmp)) {
                    if (dfs(pattern, str, patternStart + 1, i + 1, m1, m2)) return true;
                }
            } else {
                if (!m2.containsKey(tmp)) {
                    m1.put(pattern.charAt(patternStart), tmp);
                    m2.put(tmp, pattern.charAt(patternStart));
                    if (dfs(pattern, str, patternStart + 1, i + 1, m1, m2)) return true;
                    m1.remove(pattern.charAt(patternStart));
                    m2.remove(tmp);
                }
            }
        }
        return false;
    }
}
