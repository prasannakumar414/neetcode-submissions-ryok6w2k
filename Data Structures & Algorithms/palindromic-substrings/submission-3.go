func countSubstrings(s string) int {
    sum := 0
	n := len(s)
	for i := range n {
		start := i
		end := i
		sum += 1
		even := true
		odd := true
		for j := range n {
			if (j%2 == 0) {
				end++
				if (start >=0 && end < n) {
					if s[start]==s[end] && even {
						sum += 1
					}  else {
						even = false
					}
				} else {
					break
				}
			} else {
				start--
				if (start >=0 && end < n) {
				if s[start]==s[end] && odd{
					sum += 1
				}  else {
					odd = false
				}
				} else {
						break
				}
			}
			if !even && !odd {
				break
			}
		}
	}
	return sum
}