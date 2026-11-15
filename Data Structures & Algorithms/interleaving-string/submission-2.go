type Pair struct {
	First int
	Second int
}

func isInterleave(s1 string, s2 string, s3 string) bool {
	if len(s3) == len(s1) + len(s2) {
		cache := make(map[Pair]bool)
		return find(s1, s2, s3, 0, 0, cache)
	}
	return false
}

func find(s1 string, s2 string, s3 string, s1Index int, s2Index int, cache map[Pair]bool) bool {
	pair := Pair{
		First: s1Index,
		Second: s2Index,
	}
	_,exists := cache[pair]
	if exists {
		return cache[pair]
	}
	if s1Index >= len(s1) && s2Index >= len(s2) {
		if len(s3) == (s1Index + s2Index) {
			cache[pair] = true
			return cache[pair]
		}
		cache[pair] = false
		return false
	}
	if s1Index >= len(s1) {
		if (s3[s1Index + s2Index] == s2[s2Index]) {
			cache[pair] = find(s1, s2, s3, s1Index, s2Index+1, cache)
			return cache[pair]
		}
		cache[pair] = false
		return cache[pair]
	}
	if s2Index >= len(s2) {
		if (s3[s1Index + s2Index] == s1[s1Index]) {
			cache[pair] = find(s1, s2, s3, s1Index+1, s2Index, cache)
			return cache[pair]
		}
		cache[pair] = false
		return cache[pair]
	}
	s3Index := s1Index + s2Index
	if s3[s3Index] == s1[s1Index] && s3[s3Index] == s2[s2Index] {
		cache[pair] = (find(s1, s2, s3, s1Index+1, s2Index, cache) ||  find(s1, s2, s3, s1Index, s2Index+1, cache))
		return cache[pair]
	}
	if s3[s3Index] == s1[s1Index] {
		cache[pair] = find(s1, s2, s3, s1Index+1, s2Index, cache)
		return cache[pair]
	}
	if s3[s3Index] == s2[s2Index] {
		cache[pair] = find(s1, s2, s3, s1Index, s2Index+1, cache)
		return cache[pair]
	}
	cache[pair] = false
	return false
}

/*

*/