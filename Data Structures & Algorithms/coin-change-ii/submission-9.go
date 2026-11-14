func change(amount int, coins []int) int {
	row := make([]int, amount+1)
	row[0] = 1
	for i := range len(coins) {
		nextRow := make([]int, amount+1)
		nextRow[0] = 1
		for j := 1;j<=amount;j++ {
			diff := j - coins[i]
			if diff >= 0 {
		    	nextRow[j] = (nextRow[diff] + row[j])
			} else {
				nextRow[j] = row[j]
			}
		}
		row = nextRow
	}
	return row[amount] 
}