func hammingWeight(n int) int {
	count := 0
	i := 0.0
	divisor := int(math.Pow(2,i))
	for n >= divisor {
		val := n & divisor
		if val > 0 {
			count += 1
		}
		i = i + 1
		divisor = int(math.Pow(2,i))
	}
	return count
}
