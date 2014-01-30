#! /usr/bin/perl
print "Hello, World\n";
print "Arrays Names start with a @ \n";
print "Scalars Names start with a \$ \n";
print "Dictionary Names start with a % \n";
print "subroutines Names start with an & \n";

$age = 50;
$name = "Mike";

@grades_list = (100,98,43);
@people = ("Jerry Garcia", "Bobby Weir", "Phil Lesh");
$people[3] = "Mickey Hart";

%course_names = ("CS106" => "Intro to CS 1",
                 "CS206" => "Intro to CS 2",
                 "CS230" => "Programming languages");
$name = $course_names{"CS230"};

($lead, $rhythm, $bass) = @people;

print $name."\n";
print "\$people[0]\n";
print "$lead\n";
print "** is exponentiation in perl \n";
print "x multiplies the string by an integer \n";
print "no \"booleans\" per se, but instead if a scalar is 0 or \"\" then
        it is false, otherwise, it is true. \n";
print "Logical operators && || ! an, or, not alo allowed, but lower
        precedence. Both operands Short Circuit (if the first term determines
        the result, then it won't check the second operand.";

print "open a file: 
               open(FILEHAND,\"<\",\$fname) or die \"can\'t open file.\\n\"\n";


