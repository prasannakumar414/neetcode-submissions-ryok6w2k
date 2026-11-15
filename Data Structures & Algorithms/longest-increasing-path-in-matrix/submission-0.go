type Pos struct {
	row int;
	col int
}
func longestIncreasingPath(matrix [][]int) int {
    cache := make(map[Pos]int)
	rows := len(matrix)
	cols := len(matrix[0])
	max := 0
	for i := 0;i < rows;i++ {
		for j:=0;j<cols;j++ {
			m := findMax(matrix, cache, i, j)
			if m > max {
				max = m
			}
		}
	}
	return max
}

func findMax(matrix [][]int, cache map[Pos]int, row int, col int) int {
	pos := Pos{
		row : row,
		col : col,
	}
	_, exists := cache[pos]
	if exists {
		return cache[pos]
	}
	top := 0
	right := 0
	down := 0
	left := 0
	prevVal := matrix[row][col]
	if col - 1 >=0 {
		if (matrix[row][col-1] > matrix[row][col]) {
			top = findMax(matrix, cache, row, col-1)
		}
	}
	if col + 1 <len(matrix[0]) {
		if (matrix[row][col+1] > prevVal) {
			down = findMax(matrix, cache, row, col+1)
		}
	}
	if row - 1 >=0 {
		if (matrix[row-1][col] > prevVal) {
			left = findMax(matrix, cache, row-1, col)
		}
	}
	if row + 1 <len(matrix) {
		if (matrix[row+1][col] > prevVal) {
			right = findMax(matrix, cache, row+1, col)
		}
	}
	cache[pos] = max(top, left, right , down) + 1
	return cache[pos]
}
