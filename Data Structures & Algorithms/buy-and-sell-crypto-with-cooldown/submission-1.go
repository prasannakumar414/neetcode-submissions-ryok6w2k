func maxProfit(prices []int) int {
	cache := make(map[string]int)
    return find(prices, 0, cache, "BUY")
}

func find(prices []int,i int,cache map[string]int ,op string) int {
	if i >= len(prices) {
		return 0
	}
	iS := strconv.Itoa(i)
	_,exists := cache[op+iS]
	if !exists {
		profit := 0
		if op == "BUY" {
			profit = max( find(prices, i+1, cache, "BUY"),find(prices, i+1, cache, "SELL") - prices[i])
		} else {
			profit = max(find(prices, i+2, cache, "BUY") + prices[i], find(prices, i+1, cache, "SELL")) 
		}
		cache[op+iS] = profit
	}
	return cache[op+iS]
}