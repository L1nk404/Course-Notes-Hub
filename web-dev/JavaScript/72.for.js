// using button.html

function loops()
{
    var car = [
        "BMW", "Honda", "Toyota", "Mercedez", "Chevrolet", "Hyunday", "Ford"
    ];

    for (count = 0; count < car.length;
         count++) // Note that we don't have to declare count
        {
            document.write("<span style='font-size=13px'>" + (count + 1) +
                           "</span>" +
                           " " + car[count] + "<br>");
        }
}