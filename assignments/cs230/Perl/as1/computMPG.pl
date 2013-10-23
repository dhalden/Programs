#! /usr/bin/perl


sub mpg
{
$g = $_[0];
$m = $_[1];
$mpg = $m/$g;
print("Your vehicle gets $mpg miles per gallon.\n");
}



print("enter in 0 when finished.\n\n");

print("Enter number of gallons used:\n> ");
$input1 = <STDIN>;
chomp($input1);

print("Enter number of miles driven on that many gallons:\n> ");
$input2 = <STDIN>;
chomp($input2);

while($input1 and $input2)
{
    $gallons += $input1;
    $miles += $input2;

    print("Enter number of gallons used:\n> ");
    $input1 = <STDIN>;
    chomp($input1);

    print("Enter number of miles driven on that many gallons:\n> ");
    $input2 = <STDIN>;
    chomp($input2);
}

&mpg($gallons, $miles);





