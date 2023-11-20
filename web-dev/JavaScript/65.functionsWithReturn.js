// Using button.html

function print(input, id) {
    document.getElementById(id).innerHTML = input;
}

function checkEven(n) {
    var result = n % 2;
    if (result == 0) {
        return "Even";
    }
    else {
        return "Odd"
    }
}

function run_code() {
    var num = prompt("enter num");
    var answer = checkEven(num);  // In this case we're storing the value of  function
    print(answer, "title1");
}