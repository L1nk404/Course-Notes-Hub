// main is a special package that tells Go that this Package will be the main entry point of
// the application that we are building.
package main

import (
	"fmt"
	"math"
)

func main() { // We can't have two main functions in files that also bellongs to main package
	
	var investmentAmount, years float64 = 1000, 10 // investmentAmount = 1000, years = 10
	expectReturnRate := 5.5 // When we don't spectify the type we can use := to declare a variable

	// We can also convert the type in the operation
	// futureValue := float64(investmentAmount) * math.Pow(1 + exepectReturnRate / 100, float64(years))

	futureValue := investmentAmount * math.Pow(1 + expectReturnRate / 100, years)

	fmt.Printf("%.2f\n",  futureValue)
}
