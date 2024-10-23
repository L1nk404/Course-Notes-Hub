/*
 Events stands for when something happens, like "onclick"
*/

function interact(text) { document.getElementById("result").innerHTML = text; }

function input_text()
{
    var text = document.getElementById("input").value
    document.getElementById("show_input").innerHTML = text;
}