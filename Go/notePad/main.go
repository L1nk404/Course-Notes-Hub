package main

import (
	"fmt"

	"pratice.com/notePad/utilities"
)

func main() {
	utilities.ClearScreen()

	title := getUserInput("Note title: ")
	content := getUserInput("Note content: ")
}

func getUserInput(prompt string) (string) {	
	var userInput string
	
	fmt.Println(prompt)
	fmt.Scanf("%s", &userInput)

	if userInput == ""	{
		fmt.Println("Input can't be empty!")
		utilities.LoopPause()

		return getUserInput(prompt) // recursive call
	} 

	return userInput
}
