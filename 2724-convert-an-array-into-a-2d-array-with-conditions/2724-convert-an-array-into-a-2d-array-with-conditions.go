func findMatrix(nums []int) [][]int {
    m := make([]int, 201);
    res := make([][]int, 1);

    for _, n := range nums {
        m[n] += 1;
        if m[n] > len(res) {
            res = append(res, []int{n});
        } else {
            res[m[n] - 1] = append(res[m[n] - 1], n);
        }
    }

    return res;
}