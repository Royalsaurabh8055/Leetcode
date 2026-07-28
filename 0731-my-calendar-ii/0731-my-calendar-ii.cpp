class MyCalendarTwo {
public:

    map<int, int> timeline;

    MyCalendarTwo() {
    }

    bool book(int startTime, int endTime) {

        // Mark start and end
        timeline[startTime]++;
        timeline[endTime]--;

        int active = 0;

        // Prefix sum / sweep line
        for (auto &it : timeline) {

            active += it.second;

            // Triple booking
            if (active >= 3) {

                // Undo current booking
                timeline[startTime]--;
                timeline[endTime]++;

                // Optional cleanup
                if (timeline[startTime] == 0)
                    timeline.erase(startTime);

                if (timeline[endTime] == 0)
                    timeline.erase(endTime);

                return false;
            }
        }

        return true;
    }
};