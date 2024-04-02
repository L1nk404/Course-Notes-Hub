
function jsfunction()
{
    var value1 = document.getElementById("val1").value;
    var value2 = document.getElementById("val2").value;
    if (value1 >= 0)
        {
            if (value2 >= 0)
                {
                    window.alert("Both value are positive.");
                }
            else
                {
                    window.alert("Just value 1 are postive.");
                }
        }
    else
        {
            window.alert("Just value 2 are positive.")
        };
}
