import java.lang.*;
import java.math.*;
public class large
{
public static void main(String args[])
{
    BigInteger b = new BigInteger("2");
    BigInteger a = new BigInteger("2");

    for(int i = 0; i < 1000; i++)
    {
        b = b.multiply(a);
    }
    System.out.println(b);
}
}
