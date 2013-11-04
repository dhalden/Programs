public class largest_int
{


    public static void main(String args[])
    {
        BufferedReader reader = new 
			 BufferedReader(
			    new InputStreamReader
			        ( System.in ));
		

		String aLine = reader.readLine();
		String s1, s2;
		int i1, i2;

		while (aLine != null)
		{
            StringTokenizer st = new StringTokenizer(aLine);
            s1 = st.nextToken(); // get first token in file
			s2 = st.nextToken(); // get secong token in file
            i1 = Integer.parseInt(s1);
			i2 = Integer.parseInt(s2);
            while (s2 != null)
            {
                
                if(i1 > i2)
                {
                    s2 = st.nextToken();
                }
                else
                {
                    s1 = s2;
                    i1 = Integer.parseInt(s1);
                    s2 = st.nextToken();
                }
                i2 = Integer.parseInt(s2);
            }   
			// the above will treat the String aLine as 				
			// a series of tokens separated by whitespace	
			aLine = reader.readLine(); // read next line of file"
            		
		}
        System.out.print(i1);
    
    }


}





