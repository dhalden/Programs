#! /usr/bin/perl

#REGULAR EXPRESSIONS!!!!!1
# "CS230 Programming Languages"  =~ m/Prog/
# OR just       "                =~  /Prog/
# Metacharacters {}[]()^$.|*+?\ have special meaning, and must be escaped with a
# "\" character.


# ^ - forces the match to be at the beginning of the string
#   "CS230" =~ m/^CS@/; returns true
# $ (at the end) - forces the match to be at the end of the string
#  

# [] one single character in the [] is able to match
#   "Hay is for" =~ m/[A-Z]ay/; returns true
#       -may use a ^ to mean not as in [^A-Z]
#       -may use a - to represent a range of charactesr [A-Z]
#       - [a-zA-Z] (all possible letters)
#       - . (all possible characters except \n)

# these are special variables that are set for a match
# $` $& and $' (left (of matched), matched, right (of match))

"The boardgame Payday is lame" =~ m#[A-Z]ay#;
print("$`\n");
print("$&\n");
print("$'\n");

if("The boardgame Payday is lame" =~ m/.ay*/)
{
    print("$`\n");
    print("$&\n");
    print("$'\n");
}
#$x = "There once was a girl\nWho programmed in Perl\n";
#$x =~ /girl.Who/sm;# returns true because /s allows for . to be '\n' 
                   # the m in /sm is just to make sure that it checks the
                   # beginning of each line for the statement.


$tester = "Mike Eckmann teaches Programming (Languages).";

$tester =~ m/Eckmann(.*)(g(ra)m)(.*)\)/;

print "Before: >$`<\n";
print "Match: >$&<\n";
print "After: >$'<\n";

print("First parens matches: $1\n");
print("Second parens matches: $2\n");
print("Third parens matches: $3\n");
print("Fourth parens matches: $4\n");

#$x = "cats"
#$x =~ /c|ca|cat|cats/; matches "c"
#$x =~ /cats|cat|ca|c/; matches "cats"

#/house(cat|)/; #matches "housecat", or "house"
"housecatcatcat housecat" =~ m/house((cat)*)/;

print "Before: >$`<\n";
print "Match: >$&<\n";
print "After: >$'<\n";
print("First parens matches: $1\n");
print("Second parens matches: $2\n");



