#! /usr/bin/perl

$input = "(id * id) + id";

sub lex
{
    if($input =~ /^\s*(id|\+|\-|\*|\/|\(|\))/)
    {
        $nextToken = $1;
        $input = $';
        #reset input to be everything after the token
    }
    elsif($input =~ /^\s*$/)
    {
        $nextToken = "";

    }
    else
    {
        &error("didn't find valid token at beginning of '$input'");
    }
    print("found token >$nextToken<\n");
    

}


&lex();
&expr();

if ($nextToken ne "")
{
    &error("Extra stuff at the end")
}
else
{
    print("Valid Sentence\n");
}

sub expr
{
    &term();

    while ($nextToken eq "+" | $nextToken eq "-")
    {
        &lex();
        &term();
    }


}

sub term
{
    &factor();

    while($nextToken eq "*" | $nextToken eq "/")
    {
    &lex();
    &factor();
    }
}

sub factor
{
    if($nextToken eq "id")
    {
        &lex();
    }
    elsif($nextToken eq "(")
    {
        &lex();
        &expr();
        if($nextToken eq ")")
        {
            &lex();
        }
        else
        {
            &error("Expected ), but saw $nextToken");
        }
    
    }
    else
    {
        &error("expected id or (, but saw $nextToken");
    }
}
sub error
{
    print("SYNTAX ERROR: $_[0]\n");
}









