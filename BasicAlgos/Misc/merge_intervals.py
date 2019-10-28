def merge_intervals(intervals):
    intervals.sort()

    new_int = []
    cur_start,cur_end = intervals[0]
    for start, end in intervals[1:]:
        if start <= cur_end:
            cur_end = end
        else:
            new_int.append((cur_start, cur_end))
            cur_start,cur_end = start, end
    
    if cur_start != -1:
        new_int.append((cur_start, cur_end))
    return new_int


print(merge_intervals([[1, 3], [3, 5], [7, 8]]))
