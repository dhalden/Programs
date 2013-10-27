#! /usr/bin/perl


open (INFILE, "<", "expression.txt") or die ("Couldn't find file to open.");

{
    local $/;
    $input = <INFILE>;
}

sub lex
{
    if ($input =~ /^\s*(\;|\:\=|\(|\)|\,|\+|\-|\*|\/|\=|\<\>|\<|\<\=|\>\=|\>)/)
    {
        #non-word terminals
        $nextToken = $1;
        $actToken = $1
        $input = $'; #input equals everything after the terminal
    }
    elsif ($input =~ /^\s*(program|begin|read|write|if|then|else|while|do|end)/)
    {
       #word terminals
       $nextToken = $1;
       $actToken = $1;
       $input = $'; 
    }
    elsif($input =~/^\s*([0-9]+)/)
    {
        #constants
        $nextToken = "CONSTANT";
        $actToken = $1;
        $input = $';

    }
    elsif($input =~ /^\s*([A-Z][a-zA-Z0-9]*)/)
    {
        #prognames
        $nextToken = "PROGNAME";
        $actToken = $1;
        $input = $';
    }

    elsif($input =~ /^\s*([a-z][a-zA-Z0-9]*)/)
    {
        #variable
        $nextToken = "VARIABLE";
        $actToken = $1;
        $input = $';
    }

    elsif($input =~ /^\s*$/)
    {
        #if there is only space left
    }
    else
    {
        &error("didn't find a valid token, saw >$input<");
    }
    print "Found token >$nextToken<\n";
}


&lex(); #done
&program(); #done


sub program
{
    if ($nextToken eq "program")
    {
        &lex(); #done
        if($nextToken eq "PROGNAME")
        {
            &lex(); #done
            &compoundstmt(); #done
        }
        else
        {
            &error("expected PROGNAME instead found >$actToken<");
        }
    }
    else
    {
        &error("expected 'program' instead found >$actToken<"); 
    }
}

sub compoundstmt
{
    if ($nextToken eq "begin")
    {
        &lex(); #done
        &stmt(); #done

        while($nextToken eq ";")
        {
            &lex(); #done
            &stmt(); #done 
        }
        if ($nextToken eq "end")
        {
            &lex(); #done
        }
        else
        {
            &error("expected 'end' instead found >$actToken<");
        }
    }
    else
    {
        &error("expected 'begin' instead found >$actToken<");
    }
}

sub stmt
{
  if(($nextToken ne "begin") or ($nextToken ne "if") or ($nextToken ne "while"))
    {
        &simplestmt(); #done
    }
    else
    {
        &structstmt(); #done
    }

}

sub simplestmt
{
    if($nextToken eq "read")
    {
        &readstmt(); #done
    }
    elsif($nextToken eq "write")
    {
        &writestmt(); #done
    }
    elsif($nextToken eq "VARIABLE")
    {
        &assignstmt(); #done
    }
    else
    {
        &error("expected 'read', 'write', or variable, instead found
        >$actToken<");
    }
}

sub structstmt
{

    if($nextToken eq "begin")
    {
        &compoundstmt(); #done
    }
    elsif($nextToken eq "if")
    {
        &ifstmt(); #done
    }
    elsif($nextToken eq "while")
    {
        &whilestmt(); #done
    }
}

sub readstmt
{
    if($nextToken eq "read")
    {
        &lex(); #done
        if($nextToken eq "(")
        {
             &lex(); #done
             if($nextToken eq "VARIABLE")
             {
                &lex(); #done
             }
             else
             {
                &error("expected variable, instead found >$actToken<");
             }
             while ($nextToken eq ",")
             {
                &lex(); #done
                if ($nextToken eq "VARIABLE")
                {
                    &lex(); #done
                }
                else
                {
                    &error("expected variable, instead found >$actToken<");
                }
             }
             if($nextToken eq ")")
             {
                &lex(); #done
             }
             else
             {
                &error("expected ')'  instead found >$actToken<");
             }
        }
        else
        {
            &error("expected '(' instead found >$actToken<");
        }
    }
    else
    {
     &error("expected 'read' instead found >$actToken<");
    }
}

sub writestmt
{
    if($nextToken eq "write")
    {
        &lex(); #done
        if($nextToken eq "(")
        {
           &lex(); #done
           &expression(); #done
           while($nextToken eq ",")
           {
                &expression(); #done
           }
           if($nextToken eq ")")
           {
                &lex(); #done
           }
           else
           {
                &error("expected ')'  instead found >$actToken<");
           }
        }
        else
        {
            &error("expected '(' instead found >$actToken<");
        }
    }
    else
    {
        &error("expected 'write' instead found >$actToken<");
    }
}

sub assignstmt
{
    if($nextToken eq "VARIABLE")
    {
        &lex(); #done
        if($nextToken eq ":=")
        {
            &lex(); #done
            &expression(); #done
        }
        else
        {
            &error("expected ':=', instead found >$actToken<");
        }
    }
    else
    {
        &error("expected variable, instead found >$actToken<");
    }
}

sub ifstmt
{
    if($nextToken eq "if")
    {
        &lex(); #done
        &expression(); #done
        if($nextToken eq "then")
        {
            &lex(); #done
            &stmt(); #done
            if($nextToken eq "else")
            {
                &lex(); #done
                &stmt(); #done
            }
        }
        else
        {
            &error("expected 'if', instead found >$actToken<");
        }
    }
    else
    {
        &error("expected 'if', instead found >$actToken<");
    }
}

sub whilestmt
{
    if($nextToken eq "while")
    {
        &lex(); #done
        &expression(); #done
        if($nextToken eq "do")
        {
            &stmt(); #done
        }
        else
        {
            &error("expected 'do', instead found >$actToken<");
        }
    }
    else
    {
        &error("expected 'while', instead found >$actToken<");
    }
}

sub expression
{
    &simplexpr(); #done
    if($nextToken =~/^(=|<>|<|<=|>=|>)$/) #this counts as &relational_operator
    {
        &lex(); #done        
        &simplexpr(); #done
    }
}

sub simplexpr
{
    if(($nextToken eq "+") or ($nextToken eq "-")) #this counts as &sign
    {
        &lex(); #done
    }
    &term(); #done
    while(($nextToken eq "+") or ($nextToken eq "-")) #this counts as &add_op
    {
        &term(); #done
    }
}

sub term
{
    &factor(); #queued
    while(($nextToken eq "*") or ($nextToken eq "/")) #this counts as &mult_op
    {
        &factor(); #not done
    }
}

sub factor
{
    if($nextToken eq "VARIABLE")
    {
        &lex();
    }
    elsif($nextToken eq "CONSTANT")
    {
        &lex();
    }
    elsif($nextToken eq "(")
    {
        &lex();
        &expression();
        if($nextToken eq ")")
        {
            &lex();
        }
        else
        {
            &error("expected ')' instead found >$actToken<");
        }
    }
    else
    {
       &error("expected variable, constant, or '(', instead found >$actToken<");
    }
}

sub error
{
    die "SYNTAX ERROR: " . $_[0] . "\n";
}
