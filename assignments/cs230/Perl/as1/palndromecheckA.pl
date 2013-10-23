#! /usr/bin/perl

print("enter a string please:\n> ");
$input = <STDIN>;
$in = $input;
chomp($input);
chomp($in);
FOO:
{
    while($input =~ /^(.)(.*)(.)$/)
    {

        $input = $2;
        if($1 ne $3)
        {
            print("$in is not a palindrome.\n");
            last FOO;
        }


    }
}
if(length($input) <= 1)
{
    print("> $in < is a palindrome.\n")
}
