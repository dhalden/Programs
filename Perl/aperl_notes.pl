#! /usr/bin/perl

open(INPUTFILE, ">", "inputFile.txt") or die ("couldn't find the file");

print("insert item for list, and then the item price");
$nameofitem = purple;

while($nameofitem)
{
    print("First the item: ");    
    $nameofitem = <STDIN>;
    chomp($nameofitem);
    print("next the price: ");
    $priceofitem = <STDIN>;
    chomp($priceofitem);
    write($nameofitem, INPUTFILE);
    write($priceofitem, INPUTFILE);

}

close(INPUTFILE);
