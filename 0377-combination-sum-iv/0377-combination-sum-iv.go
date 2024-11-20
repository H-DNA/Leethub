import "sort"

type SIA []int;
func (arr SIA) Len() int {
    return len(arr);
}
func (arr SIA) Swap(i, j int) {
    arr[i], arr[j] = arr[j], arr[i];
}
func (arr SIA) Less(i, j int) bool {
    return arr[i] < arr[j];
}

func combinationSum4(nums []int, target int) int {
    sort.Sort(SIA(nums));
    buf := make([]int, 1001);
    buf[0] = 1;
    for i := 0; i <= target; i += 1 {
        for _, j := range nums {
            if i < j {
                break;
            }
            buf[i] += buf[i - j];
        }
    }
    return buf[target];
}