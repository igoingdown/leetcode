package main

import (
	"context"

	"code.byted.org/gopkg/logs"
)

// you can also use imports, for example:
// import "fmt"
// import "os"

// you can write to stdout for debugging purposes, e.g.
// fmt.Println("this is a debug message")

func Solution(A []int) int {
	result := len(A)
	cnt := 0
	// write your code in Go 1.4
	maxNum := -1
	for _, a := range A {
		if maxNum < a {
			maxNum = a
		}
	}

	freq := make([]int, maxNum+1)
	for _, a := range A {
		if freq[a] == 0 {
			cnt++
		}
		freq[a]++
	}

	logs.CtxInfoKvs(context.Background(), "freq", freq, "max_num", maxNum, "cnt", cnt)
	curFreq := make([]int, maxNum+1)
	for start, end := 0, 0; start < len(A) && end < len(A); end++ {
		if curFreq[A[end]] == 0 {
			cnt--
		}
		curFreq[A[end]]++
		if cnt == 0 {
			if result > end-start+1 {
				result = end - start + 1
			}
			for curFreq[A[start]] > 1 {
				curFreq[A[start]]--
				start++
			}
		}
		logs.CtxInfoKvs(context.Background(), "cur", curFreq, "res", result, "start", start, "end", end, "cnt", cnt)
	}
	return result
}

func main() {
	logs.CtxInfoKvs(context.Background(), "res", Solution([]int{2, 1, 1, 3, 2, 1, 1, 3}))
	logs.Flush()
}
