#! /usr/bin/perl
#examples of how to do things in perl

#These 2 statements are the same

$count = 0;

if(!($count))
{
    print ("unless is like if, but the condition would be reversed.\n");
    print ("unless also works with else, and elsif\n");
}

$count = 5;

unless($count)
{
    print ("unless is like if, but the condition would be reversed.\n");
    print ("unless also works with else, and elsif\n");
}

print ("multiple kinds of loops including while, until, foreach\n");
print ("the until loop is to the until loop as the unless statement is to the if
       statement\n");
print ("foreach statement ex: foreach \$element (\@people);\n");
print ("                    {print\"\$element is a person in the array\\n\";}");
print ("allows if statements aftwarwards ex: \$total++ if \$increase_total\n");

@letters = ("a", "b", "c", "d", "e");

foreach $letter (@letters)
{
    print("$letter\n");
}

#take standard input

$inline = <STDIN>;
#chomp($inline);
print "$inline";

