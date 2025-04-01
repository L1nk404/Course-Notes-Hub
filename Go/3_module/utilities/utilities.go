package utilities

/*
It's only export functions if the functions begins with uppercases
*/

import (
	"bufio"
	"errors"
	"fmt"
	"os"
	"os/exec"
	"runtime"
	"strconv"
)

// Screen

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

func LoopPause() {
	/*
	Create a buffer reader that waits to read a new line "\n"
	*/

	fmt.Printf("Press Enter to continue!\n")
	bufio.NewReader(os.Stdin).ReadBytes('\n')
}

// File operations

func WriteFloatToFile(fileName string, value float64){
	valueText := fmt.Sprintf("%f", value)

	os.WriteFile(fileName, []byte(valueText), 0755)
}

func GetFloatFromFile(fileName string, defaultValue float64) (float64, error) {
	
	data, err := os.ReadFile(fileName)

	if err != nil { // if error
		return defaultValue, errors.New("failed to find file") // creating error
	}
	
	valueString := string(data)
	
	// Converting str to float64	
	value, err := strconv.ParseFloat(valueString, 64) // 64 bytes

	if err != nil { // if there's a string that cannot be converted to float
		return 0, errors.New("failed to parse stored value")
	}

	return value, nil
}
