package main

import (
	"fmt"
	"sync"
	"sync/atomic"
)

func solution() {
	var wg sync.WaitGroup
	num := atomic.Int64{}
	num.Store(3)

	wg.Add(3)
	for i := 0; i < 3; i++ {
		j := i
		go func(id int) {
			defer wg.Done()
			num.Add(-1)
			if num.CompareAndSwap(0, -1) {
				fmt.Printf("third thread, id=%v\n", id)
			} else {
				fmt.Printf("thread, id=%v\n", id)
			}
		}(j)

	}
	wg.Wait()
}

func main() {
	solution()
}
