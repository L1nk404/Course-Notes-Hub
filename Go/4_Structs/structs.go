package main

import (
	"fmt"
	"time"
)

type User struct { // Creating a Struct
	firstName string
	lastName string
	birthDate string

	createdAt time.Time // nested Struct (Time is also a struct)
}


func main(){
	userFirtName := getUserData("Enter your first name: ")
	userLastName := getUserData("Enter your last name: ")
	userBirthDate := getUserData("Enter your birth date (DD/MM/YYYY): ")

	var appUser User // Declaring a var using User type

	appUser = User{ //Initializing
		firstName: userFirtName,
		lastName: userLastName,
		birthDate: userBirthDate,

		/* Note:
		We can just define the values like this:

		firstName,
		lastName ,
		birthDate,

		time.Now(),
		*/

		createdAt: time.Now(),
	}

	outputUserDetail(appUser);

}

func outputUserDetail(uStruct User) {
	fmt.Println(uStruct.firstName, uStruct.lastName, uStruct.birthDate, uStruct.createdAt)
}

func getUserData(promptText string) string {
	fmt.Print(promptText)
	var value string

	fmt.Scan(&value)

	return value
}