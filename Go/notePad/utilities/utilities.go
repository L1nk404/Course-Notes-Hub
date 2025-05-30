package utilities

import (
	"bufio"
	"fmt"
	"os"
	"os/exec"
	"runtime"
)

func ClearScreen() {
	var cmd *exec.Cmd

	if runtime.GOOS == "windows" {
		cmd = exec.Command("cmd", "/c", "cls")
	} else {
		cmd = exec.Command("clear")
	}

	cmd.Stdout = os.Stdout 
	
	cmd.Run()
}

func LoopPause() {
	fmt.Printf("Press Enter to continue!\n")
	bufio.NewReader(os.Stdin).ReadBytes('\n')
	ClearScreen()
}

func