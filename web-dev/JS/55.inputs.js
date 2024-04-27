function calculator(){
    var var1 = prompt("Type a int number:");
    var var2 = prompt("Type another int number:");
    document.getElementById("result").innerHTML
    = var1 + '+' + var2 + ' = ' + (1*var1 + 1*var2) + '<br>'; 
    // We multiply var1 and var2 because we want a int type of data, and prompts takes strings.
}
