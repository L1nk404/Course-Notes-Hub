
function objects()
{
    var person = {
        // Here we're creating a object
        name : "",
        age : "",
        state : "",
    };

    person.name = prompt("Enter your name: ");
    person.age = prompt("Enter your age: ");
    person.state = prompt("Enter your state: ");

    document.write("Hey " + person.name + ", you were born in " +
                   (2023 - person.age) + " on " + person.state + ".");
}
