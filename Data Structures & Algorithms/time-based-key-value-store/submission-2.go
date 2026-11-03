type Value struct {
	timestamp int
	value string
}
type TimeMap struct {
	tMap map[string][]Value
}

func Constructor() TimeMap {
	return TimeMap{
		tMap : make(map[string][]Value),
	}
}

func GetValue(timestamp int, value string) Value {
	return Value{
		timestamp: timestamp,
		value: value,
	}
}

func (this *TimeMap) Set(key string, value string, timestamp int) {
	val, ok := this.tMap[key]
	if !ok {
		val = []Value{}
	}
	val = append(val, GetValue(timestamp, value))
	this.tMap[key] = val
}

func (this *TimeMap) Get(key string, timestamp int) string {
	values := this.tMap[key]
	if(len(values)==0) {
		return ""
	}
	left := 0
	right := len(values) - 1
	mid := 0
	for(left < right) {
		mid = left + int((right-left+1)/2)
		if(values[mid].timestamp == timestamp) {
			return values[mid].value
		}
		if(values[mid].timestamp > timestamp) {
			right = mid-1
		} else {
			left = mid
		}
	}
	if(values[left].timestamp > timestamp) {
		return ""
	}
	return values[left].value
}
