#! /usr/bin/perl

$dirlisting;
if($dirlisting =~ m/^(.*)\n/)
{
    $dirlisting = $';
    $line = $1;
    if($line =~ /\d  (\d\d)\-(\d\d)\-(\d\d)\s(\S+)\s(.*)/)
    {
        print;
    }

}
