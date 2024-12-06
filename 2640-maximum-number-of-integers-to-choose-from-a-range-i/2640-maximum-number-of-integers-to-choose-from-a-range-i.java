import java.util.HashSet;
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

class Solution {
    public int maxCount(int[] banned, int n, int maxSum) {
        HashSet<Integer> numberSet = new HashSet();
        for (int i = 1; i <= n; i += 1) {
            numberSet.add(i);
        }
        for (int b: banned) {
            numberSet.remove(b);
        }
        List<Integer> numbers = new ArrayList(numberSet);
        Collections.sort(numbers);

        int count = 0;
        int sum = 0;
        for (int num: numbers) {
            sum += num;
            if (sum > maxSum) {
                return count;
            }
            count += 1;
        }
        return count;
    }
}