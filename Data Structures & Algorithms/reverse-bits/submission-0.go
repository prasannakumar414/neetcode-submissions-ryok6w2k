func reverseBits(n int) int {
	result := 0
	i := 32.0
	for n > 0 {
		i = i - 1
		result += int(math.Pow(2,i)) * (n%2)
		n=n>>1
	}
	return result
}

