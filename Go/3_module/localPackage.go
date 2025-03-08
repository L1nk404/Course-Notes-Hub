package main

import (
	"fmt"
)

// We can use this function in any other files that shared the main package
func printOptions(strings ...any){
	for index, text := range strings{
		fmt.Printf("[%d] %s\n", index + 1, text)
	}

	fmt.Printf("\n>> Enter Your choice: ")
}

