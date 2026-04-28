func longestPalindrome(s string) string {
    maxString := ""
    maxLength := 0
    for i:=0; i<len(s);i++ {
        s,l := getMaxPalindrome(s,i)
        if l>maxLength {
            maxLength = l
            maxString = s
        }
    }
    return maxString
}

func getMaxPalindrome(s string, i int) (string, int){
    maxOddString, maxOddLength := getMaxOddPalindrome(s,i)
    maxEvenString, maxEvenLength := getMaxEvenPalindrome(s,i)
    if maxOddLength > maxEvenLength {
        return maxOddString, maxOddLength
    }
    return maxEvenString, maxEvenLength
}

func getMaxOddPalindrome(s string, i int) (string, int) {
    maxString := string(s[i])
    maxLength := 1
    count := 1
    for {
        start := i - count
        end := i + count
        if (start<0 || end>=len(s)) {
            break
        }
        if (s[start]==s[end]) {
            maxString = string(s[start]) + maxString
            maxString = maxString + string(s[end])
            maxLength += 2
        } else {
            break
        }
        count += 1
    }
    return maxString,maxLength
}

func getMaxEvenPalindrome(s string,i int) (string, int) {
    if i+1 >= len(s) {
        return "",0
    }
    if s[i] != s[i+1] {
        return "",0
    }
    maxString := string(s[i])+string(s[i+1])
    maxLength := 2
    count := 1
    for {
        start := i - count
        end := i + count + 1
        if (start < 0 || end >= len(s)) {
            break
        }
        if (s[start]==s[end]) {
            maxString = string(s[start]) + maxString
            maxString = maxString + string(s[end])
            maxLength += 2
        } else {
            break
        }
        count += 1
    }
    return maxString,maxLength
}