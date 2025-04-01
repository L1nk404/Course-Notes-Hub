/*
Quick Pointer review:

- We declare a pointer using "*" in front of the type
	 -> var Pointer *int

- We also can use "*" behing a pointer to get the value of the address
- We use "&" in front of a normal var to get their address
*/

package main

import (
	"fmt"

	"module.com/structs/user"
)

func main(){
	userFirstName := getUserData("Enter your first name: ")
	userLastName := getUserData("Enter your last name: ")
	userBirthDate := getUserData("Enter your birth date (DD/MM/YYYY): ")

	var appUser *user.User // Declaring a var using *User type

	appUser, err := user.New(userFirstName, userLastName, userBirthDate)

	if err != nil {
		fmt.Println(err)
	}

	admin := user.NewAdmin("test@example.com", "password123")

	
	appUser.OutputUserDetail()
	appUser.ClearUserName()
	appUser.OutputUserDetail()
	
	admin.OutputUserDetail()
}

func getUserData(promptText string) string {
	fmt.Print(promptText)
	var value string

	fmt.Scanln(&value) // Different than Scanf, Scanln allows empty input

	return value
}