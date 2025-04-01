package user

import (
	"errors"
	"fmt"
	"time"
)


type User struct { // Creating a Struct
	firstName string
	lastName  string
	birthDate string

	createdAt time.Time // nested Struct (Time is also a struct)	
}

// Embedding with User struct (similar to Java inheritance)
// It have all the fileds of the User type, but add their own fields
type Admin struct {
	email string
	password string

	// For that we simply use the struct name in field list
	User // We can also left without give a name
}


// Constructor - starts with "new" by convention
// Using pointer in constructor are important to not just create a copy of the objects
func New(firstName, lastName, birthDate string) (*User, error) { // for User
	if firstName == "" || lastName == "" || birthDate == "" {
		return nil, errors.New("First name, last name, birthdate are required")
	}

	return &User{ // We can also initialize a struct using that syntax
		firstName: firstName,
		lastName:  lastName,
		birthDate: birthDate,

		/* Note:
		We can just define the values like this:

		firstName,
		lastName ,
		birthDate,

		time.Now(),
		*/
		createdAt: time.Now(),
	}, nil
}

func NewAdmin(email, password string) *Admin {
	return &Admin{
		email: email,
		password: password,

		User: User{ 
			firstName: "Admin",
			lastName: "",
			birthDate: "---",
			createdAt: time.Now(),
		},
	}
}

// Attaching a method to the User struct
func (receiverArg *User) OutputUserDetail() { 
	fmt.Printf("Name: %s %s, Birthday: %s\n",
		receiverArg.firstName,
		receiverArg.lastName,
		receiverArg.birthDate,
	)
}

func (u *User) ClearUserName() {
	// (*u) is a de-referecing syntax, but isn't mandatory in Go
	(*u).firstName = ""
	(*u).lastName = ""
}
