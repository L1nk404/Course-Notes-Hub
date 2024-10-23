// using button.html

function loop() // Lesson 70
{
    var count = 0;
    while (count <= 3)
        {
            alert(count);
            count++;
        }
}

function ArrayAndLoop() // Lesson 71
{
    var count = 0
    var car = [
        "BMW", "Honda", "Toyota", "Mercedez", "Chevrolet", "Hyunday", "Ford"
    ];

    while (count < car.length)
        {
            document.write("<span style='font-size=13px'>" + (count + 1) +
                           "</span>" +
                           " " + car[count] + "<br>");
            count++;
        }
}