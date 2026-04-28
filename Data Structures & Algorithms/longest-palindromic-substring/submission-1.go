import ("sync")
var wg sync.WaitGroup

func longestPalindrome(s string) string {
    ch := make(chan string)
    for i:=0; i<len(s);i++ {
        wg.Add(1)
        go getMaxPalindrome(s,i,ch)
    }
    go func() {
        wg.Wait()
        close(ch)
    } ()
    maxString := ""
    for msg := range ch {
        if len(msg) > len(maxString) {
            maxString = msg
        }
    }
    return maxString
}

func getMaxPalindrome(s string, i int,c chan<-string) {
    defer wg.Done()
    wg.Add(2)
    go getMaxOddPalindrome(s,i,c)
    go getMaxEvenPalindrome(s,i,c)
}

func getMaxOddPalindrome(s string, i int,ch chan<-string)  {
    defer wg.Done()
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
    ch <- maxString
}

func getMaxEvenPalindrome(s string,i int,ch chan<-string) {
    defer wg.Done()
    if i+1 >= len(s) {
        return
    }
    if s[i] != s[i+1] {
        return
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
    ch <- maxString
}