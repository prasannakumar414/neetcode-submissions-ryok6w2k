func uniquePaths(m int, n int) int {
    row := make([]int, n)
	for i := range n {
		row[i] = 1
	}
	for _ = range m-1 {
		newRow := make([]int, n)
		for j := range n {
			newRow[j] = 1
		}
		for j := 2; j<=n;j++ {
			newRow[n-j] = row[n-j]+newRow[n-j+1]
		}
		row = newRow
	}
	return row[0]
}

// we know one way to reach m-1, n-1, i.e one way
// now consider the last row (m-1,n-2), ..., (m-1, 0) all are ones 
// because we can only move right side and cannot move down.
// same goes to the last column (m-2, n-1), ... (0,n-1).
// so calculate a new row (m-2,0) to (m-2, n-2) where we get number 
// of paths from right and down cells.
