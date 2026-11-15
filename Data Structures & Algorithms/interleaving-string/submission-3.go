func isInterleave(s1 string, s2 string, s3 string) bool {
	if !(len(s3) == len(s1) + len(s2)) {
		return false
	}
    row := make([]bool, len(s2) + 1)
	for i:= len(s1); i >=0;i-- {
		newRow := make([]bool, len(s2) + 1)
		for j := len(s2); j >= 0;j-- {
			if (i > len(s1) - 1 && j > len(s2) - 1) {
				newRow[j] = true
				continue
			}
			if (i > len(s1) - 1) {
				newRow[j] = (s3[i+j] == s2[j]) && (newRow[j+1])
				continue
			}
			if (j > len(s2) - 1 ) {
				newRow[j] = (s3[i+j] == s1[i]) && (row[j])
				continue
			}
			if (s1[i] == s3[i+j] && s2[j] == s3[i+j]) {
				newRow[j] = newRow[j+1] || row[j]
				continue
			}
			if (s1[i] == s3[i+j]) {
				newRow[j] = row[j]
				continue
			}
			if (s2[j] == s3[i+j]) {
				newRow[j] = newRow[j+1]
				continue
			}
			newRow[j] = false
		}
		row = newRow
	}
	return row[0]
}
/*
   b b b b 
 a
 a
 a
 a          
           T
             
*/