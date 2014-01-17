#! /usr/bin/perl

open (INFILE, "<", $ARGV[0]) or die ("Couldn't find file to open.");

{
    local $/;
    $input = <INFILE>;
}

$pcount = 0;
do  {
    if($input =~ m/^[^)]*?\(/)
    {
        $input = $';
	$pcount++;
    }
    elsif($input =~ m/^.*?\)/)
    {
	$input = $';
	$pcount--;
    }
    elsif($input =~ m/^[^()]*$/)
    {
	$input = "";
    }
    print($input);
    } while($pcount >= 0 and $input);


if($pcount > 0)
{
    print("there were more '('s than ')'s\n");
}
elsif($pcount < 0)
{
    print("there was an unmatched '('\n");
}
elsif($pcount == 0)
{
    print("all good!\n");
}



