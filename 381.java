class RandomizedCollection {
    private HashMap<Integer, HashSet<Integer>> map = new HashMap<>();
    private int[] arr;
    private int pos = 0;
    private Random rnd = new Random();
    
    /** Initialize your data structure here. */
    public RandomizedCollection() {
        arr = new int[1];
    }

    public boolean insert(int val) {
        boolean res = !map.containsKey(val);
        map.putIfAbsent(val, new HashSet<>());
        map.get(val).add(pos);
        if (pos + 1 == arr.length) arr = Arrays.copyOf(arr, arr.length * 2);
        arr[pos++] = val;
        return res;
    }

    public boolean remove(int val) {
        boolean res = map.containsKey(val);
        if (res) {
            int valPos = map.get(val).iterator().next();
            map.get(val).remove(valPos);
            if (map.get(val).isEmpty()) map.remove(val);
            int tmp = arr[pos - 1];
            arr[pos - 1] = arr[valPos];
            arr[valPos] = tmp;
            if (map.containsKey(tmp)) {
                map.get(tmp).remove(pos - 1);
                map.get(tmp).add(valPos);
            }
            pos--;
        }
        return res;
    }

    public int getRandom() {
        return arr[rnd.nextInt(pos)];
    }
}

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */