class RangeModule {
    private TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();

    public RangeModule() {
        
    }
    
    public void addRange(int left, int right) {
        if (left >= right) return;
        Integer start = map.floorKey(left);
        if (start == null) start = map.ceilingKey(left);
        while (start != null && start <= right) {
            int end = map.get(start);
            if (end >= left) {
                map.remove(start);
                left = start < left ? start : left;
                right = end > right ? end : right;
            }
            start = map.ceilingKey(end);
        }
        map.put(left, right);
    }
    
    public boolean queryRange(int left, int right) {
        Integer start = map.floorKey(left);
        return start != null && map.get(start) >= right;
    }
    
    public void removeRange(int left, int right) {
        if (left >= right) return;
        Integer start = map.floorKey(left);
        if (start == null) start = map.ceilingKey(left);
        while (start != null && start < right) {
            int end = map.get(start);
            if (end > left) {
                map.remove(start);
                if (start < left) map.put(start, left);
                if (end > right) map.put(right, end);
            }
            start = map.ceilingKey(end);
        }
    }
}

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * boolean param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */