/**
 * 57. Insert Interval
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    private List<Interval> merge(List<Interval> intervals) {
        if (intervals.size() <= 1) return intervals;

        intervals.sort((a, b) -> a.start - b.start);
        List<Interval> res = new ArrayList<>();
        int start = intervals.get(0).start;
        int end = intervals.get(0).end;

        for (Interval interval : intervals) {
            if (interval.start <= end) {
                end = Math.max(end, interval.end);
            } else {
                res.add(new Interval(start, end));
                start = interval.start;
                end = interval.end;
            }
        }
        res.add(new Interval(start, end));
        return res;
    }
    
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        if (intervals.size() == 0)
            return Arrays.asList(newInterval);

        int i = 0, n = intervals.size();
        while (i < n && newInterval.start > intervals.get(i).start)
            i++;
        intervals.add(i, newInterval);
        return merge(intervals);
    }
}
