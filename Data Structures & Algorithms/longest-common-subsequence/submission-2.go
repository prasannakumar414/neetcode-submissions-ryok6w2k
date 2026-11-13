func longestCommonSubsequence(text1 string, text2 string) int {
    l1 := len(text1)
	l2 := len(text2)
	row := make([]int, l2+1)
	for i := l1-1;i>=0;i-- {
		newRow := make([]int, l2+1)
		for j:=l2-1;j>=0;j-- {
			if(text2[j] == text1[i]) {
				newRow[j] = 1+row[j+1]
			} else {
				newRow[j] = max(newRow[j+1], row[j])
			}
		}
		row = newRow
	}
	return row[0]
}

/*
to solve this problem think of subproblem as common sub sequence
in the substrings.
for example consider only one character in each that means if they
match it is +1 if not 0.
if n characters and m characters
arranging them in grid we can understand that last element in grid (m-1, n-1) means last characters match or not.
now going up at every cell we have a choice, if both characters are 
equal it means that we can add +1 to the number of subsequences we
have.
If they are not equal we can consider the character of the string where we get maximum number of subsequence.
So 
  c r a b t
c
a          1
t        1 1
the path we traverse is if characters match go diagnol
if they dont match pick max(right, down)

*/