function calculator(){
    var value = prompt("Enter a number:");
    if(value>10){
        document.write("Value is greater than 10.");
    }else if(value == 10){
        document.write("Value is equal to 10.");
    }else{
        document.write("Value is lesser than 10.");
    }
}