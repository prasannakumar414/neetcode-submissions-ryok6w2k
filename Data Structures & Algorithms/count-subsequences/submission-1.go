func numDistinct(s string, t string) int {
    m := len(s)
	n := len(t)
	row := make([]int, n+1)
	row[n] = 1
	for i := m-1; i >=0;i-- {
		newRow := make([]int, n+1)
		newRow[n] = 1
		for j := n-1; j>=0;j-- {
			if s[i] == t[j] {
				newRow[j] = row[j+1] + row[j]
			} else {
				newRow[j] = row[j]
			}
		}
		row = newRow
	}
	return row[0]
}
