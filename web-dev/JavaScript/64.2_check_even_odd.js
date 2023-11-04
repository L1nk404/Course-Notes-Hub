function ask_number() {
    var num = prompt("Enter a num");
    check_even_odd(num);
}


function check_even_odd(n) {
    var result = n % 2;
    if (result == 0) {
        alert("Even");
    }
    else {
        alert("Odd");
    }
}
