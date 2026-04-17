class Solution {
    /**
     * @param {number[]} nums
     * @return {number}
     */
    
    robHouse(nums, houseNumber, moneyMap, start) {
        if (houseNumber == nums.length - 1) {
            if(start == 0 && nums.length > 1) {
                return 0
            }
            return nums[houseNumber]
        }
        if (houseNumber >= nums.length) {
            return 0
        }
        if (moneyMap.has(`${houseNumber}|${start}`)) {
            return moneyMap.get(`${houseNumber}|${start}`)
        }
        var result = 0
        const thisHouse = nums[houseNumber] + this.robHouse(nums, houseNumber + 2, moneyMap, start)
        const nextHouse = houseNumber == 0 ? this.robHouse(nums, houseNumber + 1, moneyMap, start + 1) : this.robHouse(nums, houseNumber + 1, moneyMap, start)
        if(thisHouse > nextHouse) {
            result = thisHouse
        } else {
            result = nextHouse
        }
            
        moneyMap.set(`${houseNumber}|${start}`, result)
        return result
    }

    rob(nums) {
        const maxMoney = new Map();
        return this.robHouse(nums, 0, maxMoney, 0)
    }
}