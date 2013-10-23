/*
	Derek Halden
	1/31/2013	
	This is a cass Student score, that contains two instance variables,/
		Student - a string containing a student's name
		Score - an in containing a student's score
*/
public class StudentScore implements Comparable<StudentScore>
{
	private int studentScore;
	private String studentName;

	public StudentScore(String name, int score)
	{
		setStudentName(name);
		setStudentScore(score);
		
	}
	
	public void setStudentName(String name)
	{
		this.studentName = name;
	}
	
	public void setStudentScore(int score)
	{
		
		this.studentScore = score;
			
		
	}
	
	
	public String getStudentName()
	{
		return studentName;
	}
	
	public int getStudentScore()
	{
		return studentScore;
	}
	public String toString()
	{
		String studentInfo = new String();
		
		studentInfo = ("Student: " + studentName + "\n" + " Score: "
							 + studentScore);
		
		return studentInfo;
	}
	/*
	make sure each student is formatted properly in the files they are copied
	to.
	*/
	public String formatForFile()
	{
	
	return (studentName + " " + studentScore);
	
	}
	public int compareTo(StudentScore studentSS)
	{
		if (this.studentScore == studentSS.studentScore)
		{
			return studentName.compareTo(studentSS.studentName);
		}
		
		else
		
		{
			return this.studentScore - studentSS.studentScore;
		}
		
	}
	
}
