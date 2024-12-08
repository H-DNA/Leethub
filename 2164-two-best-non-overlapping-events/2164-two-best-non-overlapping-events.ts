function maxTwoEvents(events: number[][]): number {
    const eventsSortedByStartTime = [...events];
    eventsSortedByStartTime.sort(([s1], [s2]) => s2 - s1);
    const eventsSortedByEndTime = events;
    eventsSortedByEndTime.sort(([, e1], [, e2]) => e2 - e1);

    let maxRes = 0;
    let maxStart = 0;
    let startPtr = 0;

    for (let endPtr = 0; endPtr < eventsSortedByEndTime.length; ++endPtr) {
        while (startPtr < eventsSortedByStartTime.length && eventsSortedByStartTime[startPtr][0] > eventsSortedByEndTime[endPtr][1]) {
            maxStart = Math.max(maxStart, eventsSortedByStartTime[startPtr][2]);
            ++startPtr;
        }
        maxRes = Math.max(maxRes, maxStart + eventsSortedByEndTime[endPtr][2]);
    }
    return maxRes;
};