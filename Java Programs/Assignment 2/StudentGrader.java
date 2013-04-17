/*
	Derek Halden
	2/8/13
	StudentGrader.Java
	This program will take test scores from a file, put them in an array list, 
	and then answer questions about them. It will give the user 8 options of
	things that it can do, and once the user is finished it will allow them to 
	quit. This will permanently save the changes to the file they opened.
*/
import java.util.*;
import java.io.*;
import javax.swing.*;

public class StudentGrader
{
	/*
		Prints an array list of Student Scores in a JOptionPane
	*/

	
	public static int findNameIndex(ArrayList<StudentScore> grades)
	{
	

		  
		  String name = JOptionPane.showInputDialog("Input the name of the new student whose score you want to see or change.");
		  	for (int i = 0; i < grades.size(); i++)
		  	{
		  		StudentScore temp = grades.get(i);
		  	 
		  		if (temp.getStudentName().equals(name))
		  		{
		  			//returns the first index of the student's name.
		  			return i;
		  			
		  		}
		  		
		  		
		  	
		  	}
		  	//returns -1 if no student is found by that name	
		  	return -1;
		  	
	}
	public static ArrayList<StudentScore> populateArraylistFromFile(String file)
	{
	 
	 ArrayList<StudentScore> txtList = new ArrayList<StudentScore>();
	 
	try
		{	
		BufferedReader listOfGradesFile = new BufferedReader(new FileReader(file)); 
		
		while(listOfGradesFile.ready())
			{
			
			String line = listOfGradesFile.readLine();
			//since default includes the space character.
			//format expected to be: studentName score
			
			
			StringTokenizer st = new StringTokenizer(line);
			
			String student = st.nextToken();
			String scoreStr = st.nextToken();
			int score = Integer.parseInt(scoreStr);
			
			//add the new Student info
			StudentScore ss = new StudentScore(student, score);
			txtList.add(ss);
			
			}
			listOfGradesFile.close();
			
		} 
	catch (FileNotFoundException fnfe)
		{
			System.out.println("File not found MSG:" + fnfe.getMessage());
			 // kills the program
		} 
	catch (IOException ioe)
		{
			System.out.println("couldn't read from file MSG:" + ioe.getMessage());
			 // kills the program
		} 
		
		return txtList;
	}
	
	public static void saveArrayListToFile(ArrayList<StudentScore> grades)
	{
	
		PrintWriter pw;

	try
		{
			pw = new PrintWriter(new FileOutputStream("studentlist.txt", false));
			
			for (int i = 0; i < grades.size(); i++)
			{
				pw.println(grades.get(i).formatForFile());
			}
			pw.close();
		}
		
		catch (IOException ioe)
		
		{
			
			System.out.println("couldn't read from file MSG:" + ioe.getMessage());
			
		}
		
	}
	
	public static void printAL(ArrayList<StudentScore> grades)
	{
		String allTheGrades = "";

		for (int i= 0; i<grades.size(); i++)
		{
			allTheGrades +=	grades.get(i).toString() + "\n";
		}
		
		
		JOptionPane.showMessageDialog(null, allTheGrades);

	}
	
	
	
	public static void sort(ArrayList<StudentScore> grades)
	{
		//This is a selection sort to make methods 3, 4 and 5 easier
	
		
		StudentScore temp;
		int s = 0;
		
		int length = grades.size();
		
		for (int pass = 1; pass < length; pass++)
		{
			int position = 0;
			
			for (int i = 0; i <= (length - pass); i++)
			{
				if (grades.get(i).compareTo(grades.get(position)) > 0)
				{
					position = i;
					
				}
				s = i;
			}
			if (position != s)
			{
			 	temp = grades.get(position);
			 	grades.set(position, grades.get(s));
			 	grades.set(s, temp);
			}
			
		}
		
		
	
	}
	
	
	/*
		This part of the program first converts every line from the file
		studentgrades.txt into a "StudentScore object which it then puts into
		an Arraylist. Afterwards, it prints out the information from the 
		Array List, and then it concatenates the string that will be used
		for the main instrunctions.
	*/
	public static void main(String args[])
	{
	
	ArrayList<StudentScore> studentGrades = new ArrayList<StudentScore>();
	
	studentGrades = populateArraylistFromFile("studentlist.txt");
	
	//Creates the main dialogue
	String mainInstructions = "1 Add a student and a test score to the list of students/scores." + "\n"
							 + "2 Find the score for a particular student." + "\n"
							 + "3 Find the student with the maximum score." + "\n"
	 						 + "4 Find the student with the minimum score." + "\n"
	 						 + "5 Display the students sorted by test score." + "\n"
	                         + "6 Delete a student." + "\n"
	                         + "7 Change a score for a particular student." + "\n"
	                         + "8 Quit" + "\n"
                             + "Choose the number corresponding to the item you want" + "\n";
	
	
	
	int choice = 0;
	
	//no guarantee the list starts in order.
	//sort method makes numbers 3, 4 and 5 work faster.
	sort(studentGrades);
	
	/*
		This is the while statement that is the majority of the program
		depending on the user's choice of number.
		The Program runs as a series of if statements that check to see which
		option the user has chosen. 
		
	*/
	while (choice != 8)
		{
		
    	//prompts user with the instructions each time in a JOptionPane
		//asks them to pick a number between 1 and 8
		String c = JOptionPane.showInputDialog(null, mainInstructions);
		choice = Integer.parseInt(c);
		
		if(choice == 1)
			{
				//let's user input the name and score of a new student
				//then adds the student to the list
				String name = JOptionPane.showInputDialog("Input the name of the new student.");
				String scoreStr = JOptionPane.showInputDialog("Input the score of the new student.");
				int score = Integer.parseInt(scoreStr);
				
				//add the new student to the ArrayList
				StudentScore newKid = new StudentScore(name, score);
				studentGrades.add(newKid);
				
				//the list will no longer be sorted at this point
				sort(studentGrades);
			
			}
		if(choice == 2)
		{
		  	//let's user input a student name, 
		  	//and then prints the score for that student
		  	int nameIndex = 0;
		  	nameIndex = findNameIndex(studentGrades);
		  	if (nameIndex > -1)
		  	{
		  		String studentInfo = studentGrades.get(nameIndex).toString();
		  		JOptionPane.showMessageDialog(null,studentInfo);
		  	}
		  	else
		  	{
		  		JOptionPane.showMessageDialog(null, "that student doesn't exist");
		  	}
		}
		if (choice == 3)
		{
			/*
			note that the list is already sorted by scores
			from smallest to largest.
			*/
			JOptionPane.showMessageDialog(null, studentGrades.get(studentGrades.size() - 1));
		
		}	
		if (choice == 4)
		{
			//note grades still sorted smallest to largest
			JOptionPane.showMessageDialog(null,studentGrades.get(0));
		
		}
		if (choice == 5)
		{
			
			/*
			the list is already sorted, so there's only really need 
			to print out the list.
			*/
			printAL(studentGrades);
			
		}
		
		if(choice == 6)
		{
			//This will delete a student by name
			
			int nameIndex = findNameIndex(studentGrades);
			  			
			if (nameIndex > -1)
			{ 			
				studentGrades.remove(nameIndex);
			}  			
			  			
			else
			{
				JOptionPane.showMessageDialog(null, "that student doesn't exist");
		  	}	
				  			
			  
			
		}
		
		if(choice == 7)
		{
		
			/*
			This will find a student by name and change their score to 
			the inputted score.
			*/
			
			int nameIndex = findNameIndex(studentGrades);
			
			String scoreStr = JOptionPane.showInputDialog("Input the new score you would like to give this student.");
			int score = Integer.parseInt(scoreStr);
			
			if (nameIndex > -1)
			{ 			
				studentGrades.get(nameIndex).setStudentScore(score);
			}  			
			  			
			else
			{
				JOptionPane.showMessageDialog(null, "that student doesn't exist");
		  	}	
		  		
		  	//since the score is changed after this method is called, the list could be out of order
		  	sort(studentGrades);	
		  			
		  }		
		  			
		 
		
		
		
		
		}
	
	/*
	after leaving the while loop, since all of the changes have been made,
	the program will now write the changes to the file.
	*/
		saveArrayListToFile(studentGrades);
		
	}
}
