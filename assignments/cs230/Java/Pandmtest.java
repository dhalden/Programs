import java.util.regex.Pattern;
import java.util.regex.Matcher;
import java.util.*;
import java.io.*;
public class Pandmtest
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        Pattern p = Pattern.compile("([a-zA-z']+)");
        sc.useDelimiter("\\Z");
        String content = sc.next();
        Matcher m = p.matcher(content);
        while(m.find() == true)
        {
            System.out.println(m.group());
            int i = m.end();
            if(i < content.length())
            {
                content = content.substring(i, content.length());
            }
            else
            {
                break;
            }
            m = p.matcher(content); 
        }
    }

}
