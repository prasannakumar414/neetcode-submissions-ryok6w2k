
func countBits(n int) []int {
	m := make(map[int]int)
	len := n+1
	res := make([]int, len)
	for i := range n+1 {
		res[i] = countOnes(i,m)
	}
	return res
}

func countOnes(n int,m map[int]int) int {
	val, ok := m[n]
	if ok {
		return val
	}
	count := 0
	for n > 0 {
		n = n & (n-1)
		count += 1
	}
	return count
}
