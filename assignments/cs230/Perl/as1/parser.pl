#! /usr/bin/perl


open (INFILE, "<", $ARGV[0]) or die ("Couldn't find file to open.");
{
    local $/;
    $input = <INFILE>;
}

sub lex
{
    if ($input =~ /^\s*(\;|\:\=|\(|\)|\,|\+|\-|\*|\/|\=|\<\>|\<\=|\>\=|\>|\<)/)
    {
        #non-word terminals
        $nextToken = $1;
        $actToken = $1;
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
        $nextToken = "";
    }
    else
    {
        chomp($input);
        &error("didn't find a valid token, saw >$input<");
        #as tested by err1.txt
    }
    #print "Found token >$nextToken<\n";
}


&lex(); #done
&program(); #done
if($nextToken ne "")
{
    &error("Unexpected addition at the End of File >$actToken<")
    #as tested by err2.txt
}
else
{
    print "\n"; 
}

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
            #as tested by err3.txt
            &error("expected PROGNAME instead found >$actToken<");
        }
    }
    else
    {
        #as tested by err4.txt
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
            #as tested by err5.txt
            &error("expected 'end' instead found >$actToken<");
        }
    }
    else
    {
        #as tested by err6.txt
        &error("expected 'begin' instead found >$actToken<");
    }
}

sub stmt
{
  if(($nextToken ne "begin") xor ($nextToken ne "if") xor ($nextToken ne "while"))
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
        #as tested by err7.txt
        &error("expected beginning of a statement, instead found
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
                # as tested by err8.txt
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
                    # this would be the same check as err8, there would just
                    # be more variables in the statement.
                    &error("expected variable, instead found >$actToken<");
                }
             }
             if($nextToken eq ")")
             {
                &lex(); #done
             }
             else
             {
                #as tested by err9.txt
                &error("expected ')'  instead found >$actToken<");
             }
        }
        else
        {
            #as tested by err10.txt
            &error("expected '(' instead found >$actToken<");
        }
    }
    else
    {
     &error("expected 'read' instead found >$actToken<");
     # I actually guarantee ahead of time, in &simplestmt that this can't happen
     # that said, I wrote it anyways just in case it actually does happen
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
                &lex();
                &expression(); #done
           }
           if($nextToken eq ")")
           {
                &lex(); #done
           }
           else
           {
                # as tested by err12.txt
                &error("expected ')'  instead found >$actToken<");
           }
        }
        else
        {
            # as tested by err11.txt
            &error("expected '(' instead found >$actToken<");
        }
    }
    else
    {
        &error("expected 'write' instead found >$actToken<");
        # this also cannot happen because of &simplestmt
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
            # as tested by err13.txt
            &error("expected ':=', instead found >$actToken<");
        }
    }
    else
    {
        &error("expected variable, instead found >$actToken<");
        # this also cannot happen because of &simplestmt
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
            # as tested by err14.txt
            &error("expected 'then', instead found >$actToken<");
        }
    }
    else
    {
        &error("expected 'if', instead found >$actToken<");
        # this line, is unreachable because of the &stmt method
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
            &lex(); #done
            &stmt(); #done
        }
        else
        {
            #as tested by err15.txt
            &error("expected 'do', instead found >$actToken<");
        }
    }
    else
    {
        &error("expected 'while', instead found >$actToken<");
        # this line, is similarly unreachable because of the &stmt, method
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
        &lex(); #done
        &term(); #done
    }
}

sub term
{
    &factor(); #done
    while(($nextToken eq "*") or ($nextToken eq "/")) #this counts as &mult_op
    {
        &lex();
        &factor(); # done
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
            # as tested by err17.txt
            &error("expected ')' instead found >$actToken<");
        }
    }
    else
    {
         #as tested by err18.txt
       &error("expected variable, constant, or '(', instead found >$actToken<");
    }
}

sub error
{
    die "SYNTAX ERROR: " . $_[0] . "\n";
}
