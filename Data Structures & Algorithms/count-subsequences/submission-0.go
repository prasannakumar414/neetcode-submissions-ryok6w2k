type Pair struct {
	First int;
	Second int;
}
func numDistinct(s string, t string) int {
	cache := make(map[Pair]int)
	return find(s, t, cache, 0,0)
}

func find(s string, t string, cache map[Pair]int, i int, j int) int{
	p := Pair{
		First : i,
		Second : j,
	}
	_, exists := cache[p]
	if !exists {
		if j == len(t) {
			cache[p] = 1
		} else if i == len(s) {
			cache[p] = 0
		} else if s[i] == t[j] {
			cache[p] = find(s, t, cache, i + 1, j+1) + find(s, t, cache, i+1, j)
		} else {
			cache[p] = find(s, t, cache, i+1, j)
		}
	}
	return cache[p]
}
