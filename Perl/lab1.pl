#! /usr/bin/perl

$onezee = "zzzzzzzzzzzzzzzzzzzzzzz"; #works
#$onezee = "1s"; #doesn't work
if($onezee =~ m/(1)*z+/)
{
print("$`\n");
print("$&\n");
print("$'\n");
}
else
{
    print("\nNope, didn't match\n");
}
print("\n\n");
$stringcheese = "tac man cat cat cat tac grep"; #works
#$stringcheese = "tac man grep"; #doesn't work
$matchword = "cat ";
if($stringcheese =~ m/($matchword)+/)
{
print("$`\n");
print("$&\n");
print("$'\n");

}
else
{
    print("\nNope, didn't match\n");
}

$dollarvalue = "\$100.50 "; #works
#$dollarvalue = "\$1000.000"; #doesn't work
if($dollarvalue =~ m/\$(\d)+(\.)(\d){2}[^\d]/)
{
print("$`\n");
print("$&\n");
print("$'\n");
}
else
{
    print("\nNope, didn't match\n");
}


$multiplication = "5000   *  9"; #works
#$multiplication = "65e    * 7"; #doesn't work
if($multiplication =~ m/(\d)+(\s)*[*x](\s)*(\d)+/)
{
print("$`\n");
print("$&\n");
print("$'\n");
}
else
{
    print("\nNope, didn't match\n");
}


