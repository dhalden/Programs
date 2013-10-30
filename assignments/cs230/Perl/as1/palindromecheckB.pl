#! /usr/bin/perl

print("enter a string please:\n> ");
$input = <STDIN>;
$in = $input;

print("\n\n\n");

chomp($input);
chomp($in);
$ispal = &pcheck($in);
print(".\n");

$buildstr = "";
$imp = $input;
if(!$ispal)
{
BAR:
    {
        if($imp =~ /([^\s.;,])(.*)/)
        {
            $buildstr = $buildstr.$1;
            $imp = $2;
            goto BAR;
        } 
    }   

$buildstr = lc($buildstr);
&pcheck($buildstr);
print(" if I ignore whitespace, punctuation and case.\n");
}




sub pcheck
{
    $inp = $_[0];
    while($inp =~ /^(.)(.*)(.)$/)
    {

        $inp = $2;
        if($1 ne $3)
        {
           print(">$in< is not a palindrome");
           return 0;
        }
    }
    #if(length($inp) <= 1)
    #{
        print(">$in< is a palindrome");
        return 1;
    #}
}
