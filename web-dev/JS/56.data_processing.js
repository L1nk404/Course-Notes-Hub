function calc(){
    var var1 = document.getElementById("val1").value;
    var var2 = document.getElementById("val2").value;
    // Here we'll create a input box with the result value:
    document.getElementById("result").innerHTML =
    '<input type="text" value="' + (1*var1 + 1*var2) + '">'
}