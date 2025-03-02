//go:build essencials

// main is a special package that tells Go that this Package will be the main entry point of
// the application that we are building.
package main

import (
	"fmt"
	"math"
)

const inflationRate  = 2.5  // declaring a constant, if ouside function, it has global scope

func main() { // We can't have two main functions in files that also bellongs to main package
	
	var investmentAmount, years float64 = 1000, 10 // investmentAmount = 1000, years = 10
	expectReturnRate := 5.5 // When we don't spectify the type we can use := to declare a variable

	// We can also convert the type in the operation
	// futureValue := float64(investmentAmount) * math.Pow(1 + exepectReturnRate / 100, float64(years))

	fmt.Print("Enter the investment amount: ")
	fmt.Scan(&investmentAmount) // Passing a pointer to investAmount

	fmt.Print("Enter the years that you expect to invest: ")
	fmt.Scan(&years)

	fmt.Print("Enter the expected return rate: ")
	fmt.Scan(&expectReturnRate)

	
	// Storing two values from calcFuture
	futureValue, realFutureValue := calcFutureValue(investmentAmount, expectReturnRate, years)
	
	// Let's store the string in a var
	formattedFV := fmt.Sprintf("\nFuture value: $%.2f\n",  futureValue)
	formattedRFV := fmt.Sprintf("Real future value: $%.2f\n", realFutureValue)
	
	outputText(formattedFV, formattedRFV)
}

func outputText(text, text2 string){
	fmt.Print(text)
	fmt.Print(text2)
}

// (float64, float64) is the return type declared
func calcFutureValue(investmentAmount, expectReturnRate, years float64 ) (float64, float64){	
	futureValue := investmentAmount * math.Pow(1 + expectReturnRate / 100, years)
	realFutureValue:= futureValue / math.Pow(1 + inflationRate / 100, years)

	return futureValue, realFutureValue
}