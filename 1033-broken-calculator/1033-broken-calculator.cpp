class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int steps = 0;
        while (target > startValue) {
          if (target & 1) {
            target = (target + 1) >> 1;
            steps += 2;
        }
          else {
            target = target >> 1;
            ++steps;
          }
        }
        return steps + (startValue - target);  
    }
};