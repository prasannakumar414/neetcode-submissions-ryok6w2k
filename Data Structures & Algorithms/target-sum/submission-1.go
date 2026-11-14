func findTargetSumWays(nums []int, target int) int {
	cache := make(map[string]int)
    return find(nums, target, cache, 0)
}

func find(nums []int, target int, cache map[string]int, index int) int {
	if index == len(nums) {
		if (target == 0) {
			return 1
		} else {
			return 0
		}
	}
	key := getKey(index, target)
	_, exists := cache[key]
	if exists {
		return cache[key]
	}
	cache[key] = find(nums, target + nums[index], cache, index+1) + find(nums, target-nums[index], cache, index+1)
	return cache[key]
}

func getKey(a int, b int) string {
	sA := strconv.Itoa(a)
	sB := strconv.Itoa(b)
	return sA+sB
}