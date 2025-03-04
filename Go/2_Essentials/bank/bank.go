package main

import (
	"bufio"
	"errors"
	"fmt"
	"os"
	"os/exec"
	"runtime"
	"strconv"
)

func ClearScreen() {
	/*
	This function clears the terminal screen.
	*/

	var cmd *exec.Cmd // Pointing to the Cmd struct

	// checking the Operating System using runtime.GOOS
    if runtime.GOOS == "windows" { 
		cmd = exec.Command("cmd", "/c", "cls")
		} else {
			cmd = exec.Command("clear")
		}

		// Sends the cmd output o the same place where your Go program’s output goes (terminal in this case)
		cmd.Stdout = os.Stdout  
		// Runs the command
		cmd.Run()
}

func loopPause() {
	/*
	Create a buufer reader that waits to read a new line "\n"
	*/

	fmt.Printf("Press Enter to continue!\n")
	bufio.NewReader(os.Stdin).ReadBytes('\n')
}

func writeBalanceToFile(balance float64){
	balanceJson := fmt.Sprintf("%f", balance)

	os.WriteFile(accountBalanceFile, []byte(balanceJson), 0755)
}

func readBalanceFromFile() (float64, error) {
	data, err := os.ReadFile(accountBalanceFile)

	/* Error Handling:
	 if success => err == nil
	*/

	if err != nil { // if error
		return 0, errors.New("failed to find balance file") // creating error
	}
	
	balanceText := string(data)
	
	// Converting str to float64	
	balanceFloat, err := strconv.ParseFloat(balanceText, 64) // 64 bytes

	if err != nil { // if there's a string that cannot be converted to float
		return 0, errors.New("failed to parse stored balance value")
	}

	return balanceFloat, nil
}

func printOptions(strings ...any){
	for index, text := range strings{
		fmt.Printf("[%d] %s\n", index + 1, text)
	}

	fmt.Printf("\n>> Enter Your choice: ")
}

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


// Main ==============================================

const accountBalanceFile = "balance.json"

func main(){
	ClearScreen()

	var choice int
	var accountBalance, err = readBalanceFromFile()
	
	if err != nil {
		fmt.Printf("ERROR!\n")
		fmt.Println(err)
		fmt.Printf("-------------------------\n")
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

		writeBalanceToFile(accountBalance)

		loopPause()
	}


}

