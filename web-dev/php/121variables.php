<?php
$title_of_the_page = "Title";
$welcome_statement = "Welcome";
?>
<!DOCTYPE html>
<html lang="en">

<head>
    <title>
        <?php echo "$title_of_the_page";?>
    </title>
    <style>
    body {
        background-color: grey;
    }
    </style>
</head>

<body>
    <h1><?php echo "$welcome_statement"; ?></h1>
    <?php
    // we use dot (.) to concatenate
    echo "The lenght of is $welcome_statement " . strlen($welcome_statement);
    ?>
</body>

</html>