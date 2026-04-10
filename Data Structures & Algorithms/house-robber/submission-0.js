class Solution {
    /**
     * @param {number[]} nums
     * @return {number}
     */
    
    robHouse(nums, houseNumber, moneyMap) {
        if (houseNumber >= nums.length) {
            return 0
        }
        if (moneyMap.has(houseNumber)) {
            return moneyMap.get(houseNumber)
        }
        const result = Math.max(
            nums[houseNumber] + this.robHouse(nums, houseNumber + 2, moneyMap),
            this.robHouse(nums, houseNumber + 1, moneyMap)
            )
        moneyMap.set(houseNumber, result)
        return result
    }

    rob(nums) {
        const maxMoney = new Map();
        return this.robHouse(nums, 0, maxMoney)
    }
}
