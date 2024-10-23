<?php
    $gender = array(
        'maria' => "female",
        'jhon' => "male", 
        'sara' => "female", 
        'other name' => "male"
        );
    
    foreach ($gender as $name => $name_value) // To print the array we need to use foreach
    {
        echo "$name - $name_value\n";
    }

?>