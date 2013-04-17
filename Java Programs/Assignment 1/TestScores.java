/*	Derek Halden
	1/31/2013 

	New class that tests the StudentScore class
*/

public class TestScores
{
	public static void sort(Comparable list[])
	{
		
		Comparable temp;
		int s = 0;
		
		int length = list.length;
		
		for (int pass = 1; pass < length; pass++)
		{
			int position = 0;
			
			for (int i = 0; i <= (length - pass); i++)
			{
				if (list[i].compareTo(list[position]) > 0)
				{
					position = i;
					
				}
				s = i;
			}
			if (position != s)
			{
			 	temp = list[position];
			 	list[position] = list[s];
			 	list[s] = temp;
			 }
			
		}
		
		
	}
	
	public static void printStudentInfo(StudentScore list[])
	{
		String allTheStudentInfo =  "";
		
		for (int i = 0; i < list.length; i++)
		{
			
			allTheStudentInfo += list[i].toString() + "\n";
			
		}
		
		System.out.println(allTheStudentInfo);
	}
	
	
	public static void main(String[] args)
	{
		StudentScore listOfStudentScores[] = new StudentScore[10];
		
		listOfStudentScores[0] = new StudentScore("Jack", 80);
		listOfStudentScores[1] = new StudentScore("Jill", 83);
		listOfStudentScores[2] = new StudentScore("John", 43);
		listOfStudentScores[3] = new StudentScore("Joe", 95);
		listOfStudentScores[4] = new StudentScore("Jake", 92);
		listOfStudentScores[5] = new StudentScore("Jake", 98);
		listOfStudentScores[6] = new StudentScore("Jim", 12);
		listOfStudentScores[7] = new StudentScore("Julian", 59);
		listOfStudentScores[8] = new StudentScore("Jeff", 73);
		listOfStudentScores[9] = new StudentScore("Jeffrey", 81);
		
		printStudentInfo(listOfStudentScores);
		sort(listOfStudentScores);
		printStudentInfo(listOfStudentScores);
		
		
	}
		
	 
}	
