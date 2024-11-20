func generate_next_row(prevRow []int) []int {
    nextRow := make([]int, 0);
    nextRow = append(nextRow, 1);
    for i := range prevRow[1:] {
        nextRow = append(nextRow, prevRow[i] + prevRow[i + 1]);
    }
    nextRow = append(nextRow, 1);
    return nextRow;
}

func generate(numRows int) [][]int {
    res := make([][]int, 0);
    res = append(res, []int{1});
    for i := 1; i < numRows; i += 1 {
        res = append(res, generate_next_row(res[i - 1]));
    }
    return res;
}