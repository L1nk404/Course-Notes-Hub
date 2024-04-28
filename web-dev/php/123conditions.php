<?php
    $val1 = "12";
    $val2 = 56;

    if ($val1 === 13 xor $val1 == 56  ) // xor is used when we want only ONE CONDITION to be true ( exclusively or )
    // We use === to compare the value and the type, 
    //in this case $val1 is not === 12, because it's string type
    {
        echo "true\n";
    }
    else
    {
        echo "false\n";
    }
?>