<?php

if (isset($_POST['submit'])) // Checks if a variable is set => (When submit is clicked)
{
    $name = $_POST['name'];
    if ($name == "admin" && $_POST['password'] == "admin") {
        echo "Deu bom";
    } else {
        echo "Credenciais inválidas";
    }
}
?>

<!DOCTYPE html>
<html lang="en">

<head>

    <title>Form Handle</title>
</head>

<body>
    <br><br><a href="139Form.php">Back</a><br><br>
    Welcome <?php echo $name; ?><br>
</body>

</html>