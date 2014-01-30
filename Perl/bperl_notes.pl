#! /usr/bin/perl
open(INPUTFILE, "<", "inputFile.txt") or die("couldn't find the file");

$idx = 0;

$aline = <INPUTFILE>;
chomp($aline);

while($aline ne "eof")
{
    $products[$idx++] = $aline;
    $aline = <INPUTFILE>;
    chomp($aline);
}


%prodPrices = @products;

print "Enter a product or q to quit";

chomp($input = <STDIN>);
while($input ne "q")
{
    unless($prodPrices{$input})
    {
        print "Go somewhere else to buy $input.\n";
    }
    else
    {
        print "the price of $input is $prodPrices{$input}.\n";
    }
    chomp($input = <STDIN>);
 
}

close(INPUTFILE);
