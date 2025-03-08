package main

import (
	"fmt"
	"os"

	"module.com/package/utilities"
)


func balanceChange(changeType int, accountBalance float64) float64 {
	var Amount float64

	fmt.Scanf("%f", &Amount)

	if changeType == 1{ // deposit
		accountBalance += Amount
	} else {
		accountBalance -= Amount
	}

	fmt.Printf("Balance updated ! New amount: $%.2f\n", accountBalance)
	
	return accountBalance
} 


// Main ==============================================================

const accountBalanceFile = "balance.json"

func main(){
	utilities.ClearScreen()

	var choice int
	var accountBalance, err = utilities.GetFloatFromFile("../balance.json", 0)
	
	if err != nil {
		fmt.Printf("Unable to find balance file. Creating a new one!")
	}

	for {		

		fmt.Printf("Welcome to Go Bank!\n")
		fmt.Printf("What do you want to do?\n\n")
		
		printOptions("Check Balance",
		"Deposit Money",
		"Withdraw Money",
		"Exit")
	
		fmt.Scanf("%d", &choice)
	
		switch choice {
		case 1:
			fmt.Printf("Balance: $%.2f\n", accountBalance)
		case 2:
			fmt.Printf("Your deposit: ")
			accountBalance = balanceChange(1, accountBalance)
		case 3:
			fmt.Printf("Your deposit: ")
			accountBalance = balanceChange(1, accountBalance)
		case 4:
			fmt.Printf("Goodbye!\n")
			os.Exit(0)
		default:
			fmt.Printf("Invalid input!\n")
		}

		utilities.WriteFloatToFile(accountBalanceFile ,accountBalance)

		utilities.LoopPause()
		utilities.ClearScreen()
	}
}

