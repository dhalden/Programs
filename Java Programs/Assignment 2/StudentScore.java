/*
	Derek Halden
	1/31/2013	
	This is a cass Student score, that contains two instance variables,
		Student - a string containing a student's name
		Score - an in containing a student's score
*/
public class StudentScore implements Comparable<StudentScore>
{
	private int studentScore;
	private String studentName;
	
	//Only constructor takes both a string and an int
	public StudentScore(String name, int score)
	{
		setStudentName(name);
		setStudentScore(score);
		
	}
	//Takes in the new Name for the student
	public void setStudentName(String name)
	{
		this.studentName = name;
	}
	//takes in the new Score for the student.
	public void setStudentScore(int score)
	{
		
		this.studentScore = score;
			
		
	}
	
	// returns the students name
	public String getStudentName()
	{
		return studentName;
	}
	//returns the students score
	public int getStudentScore()
	{
		return studentScore;
	}
	// converts the Student Score into a string format looks like:
	//Student: studentName
	//Score: studentScore
	public String toString()
	{
		String studentInfo = new String();
		
		studentInfo = ("Student: " + studentName + "\n" + " Score: "
							 + studentScore);
		
		return studentInfo;
	}
	/*
	This method is to make sure each student is formatted properly in 
	the files they are copied to.
	Format Ex: studentName 12
	*/
	public String formatForFile()
	{
	
	return (studentName + " " + studentScore );
	
	}
	
	//takes in a StudentScore and then compares this studentScore to the parameter
	//StudentScore. Returns the difference between the two. With a positive integer
	//signalling that this StudentScore is bigger than the parameter it took in.
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
