import java.util.ArrayList;
import java.util.List;
import java.util.ListIterator;

public class RainDrop {

    public static class Interval{
        double start;
        double end;
        public Interval(double s, double e) {
            start = s;
            end = e;
        }

    }

    public static int rainDrops(double[][] rain) {
        List<Interval> intervals = new ArrayList<>();
        intervals.add(new Interval(rain[0][0], rain[0][1]));
        for (int i = 1; i < rain.length; i++) {
            if (intervals.size() == 1 && intervals.get(0).start <= 1e-5 && intervals.get(0).end >= 1 - 1e-5) return i;
            else insertInterval(intervals, new Interval(rain[i][0], rain[i][1]));
        }
        if (intervals.size() == 0 && intervals.get(0).start <= 1e-5 && intervals.get(0).end >= 1 - 1e-5) return rain.length;
        return -1;
    }

    public static void insertInterval(List<Interval> intervals, Interval newInterval) {
        ListIterator<Interval> iter = intervals.listIterator();
        while (iter.hasNext()) {
            Interval tmpInterval = iter.next();
            if (newInterval.end < tmpInterval.start) {
                iter.previous();
                iter.add(newInterval);
                return;
            } else {
                if (newInterval.start > tmpInterval.end) continue;
                else {
                    newInterval.start = Math.min(newInterval.start, tmpInterval.start);
                    newInterval.end = Math.max(newInterval.end, tmpInterval.end);
                    iter.remove();
                }
            }
        }
        intervals.add(newInterval);
    }

    public static void main(String[] args) {
        double[][] rain = {
                {0, 0.3}, {0.5, 0.8}, {0.3, 0.6}, {0.67, 1}, {0.74, 0.9}
        };
        System.out.println(rainDrops(rain));
    }

}


