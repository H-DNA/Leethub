func minFallingPathSum(matrix [][]int) int {
    dim := len(matrix);
    row := make([]int, dim);
    lastRow := matrix[0];

    for i := range matrix {
        if i == 0 {
            continue;
        }
        for j, val := range lastRow {
            row[j] = val;
            if j - 1 >= 0 {
                row[j] = min(row[j], lastRow[j - 1]);
            }
            if j + 1 < dim {
                row[j] = min(row[j], lastRow[j + 1]);
            }
            row[j] += matrix[i][j];
        }
        copy(lastRow, row);
    }

    min_v := lastRow[0];
    for _, v := range lastRow {
        min_v = min(min_v, v);
    }

    return min_v;
}