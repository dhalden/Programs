/*
	DLLSGrader.java
	
	Keeps a running dialogue box which allows the user to make adjustments to
	a doubley linked list that keeps StudentScores.
	Allows the User to modify that list of StudentScores.
	
	Author: Derek Halden
	Date: 3/21/2013	
*/
import java.io.*;
import java.util.*;
import javax.swing.*;


public class DLLSGrader
{
	//Takes in the name of a file, and makes a Doubley Linked List from that file
	//NOTE THE FILE FOR THIS PROGRAM IS NAMED: studentlist.txt
	//Returns a Doubley Linked list.
	public static DLList populateDLListFromFile(String file)
	{
	DLList txtList = new DLList();
	 
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
			txtList.addInSortOrder(ss);
			
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
	
	
	
	
	public static void main(String args[])
	{
	
	DLList studentGrades = new DLList();
	
	studentGrades = populateDLListFromFile("studentlist.txt");
	
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
	
	//The list starts in order because of my setup for populateDLListFromFile
	//and it's use of addInSortOrder(ss)
	
	
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
				//This method adds the kid in the order he would be added in.
				//this saves having to implement a sort method (though it's still written in case someone
				//needs it)
				studentGrades.addInSortOrder(newKid);
			
			}
		if(choice == 2)
		{
		  	//let's user input a student name, 
		  	//and then prints the score for that student
		  
		  	String name = JOptionPane.showInputDialog("Input the name of the new student whose score you want to see.");
		  	StudentScore ss = studentGrades.findSSWithName(name);
		  	
		  	if (ss != null)
		  	{
		  		String studentInfo = ss.toString();
		  		JOptionPane.showMessageDialog(null, studentInfo);
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
			if(!studentGrades.isEmpty())
			{
				JOptionPane.showMessageDialog(null, studentGrades.getTailSS());
			}
			else
			{
			JOptionPane.showMessageDialog(null, "The list is empty");
			}
		}	
		if (choice == 4)
		{
			//note grades still sorted smallest to largest
			if(!studentGrades.isEmpty())
			{
			JOptionPane.showMessageDialog(null,studentGrades.getHeadSS());
			}
			else
			{
			JOptionPane.showMessageDialog(null, "The list is empty");
			}
		}
		if (choice == 5)
		{
			
			/*
			the list is already sorted, so there's only really need 
			to print out the list.
			*/
			JOptionPane.showMessageDialog(null,studentGrades.toStringForward());
			
		}
		
		if(choice == 6)
		{
			//This will delete a student by name
			String name = JOptionPane.showInputDialog("Input the name of the new student whose score you want to delete.");
			StudentScore ss = studentGrades.findSSWithName(name);
			
			  			
			if (ss != null)
			{ 			
				studentGrades.delete(ss);
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
			//maybe make this into a separate method.
			String name = JOptionPane.showInputDialog("Input the name of the new student whose score you want to see or change.");
			StudentScore ss = studentGrades.findSSWithName(name);
			
			if (ss != null)
			{ 			
				studentGrades.delete(ss);
				int newScore = Integer.parseInt(JOptionPane.showInputDialog("Input the new score you want to give that student"));
				ss.setStudentScore(newScore);
				studentGrades.addInSortOrder(ss);
			}  			
			  			
			else
			{
				JOptionPane.showMessageDialog(null, "that student doesn't exist");
		  	}	
		  		
			
		  			
		  }		
		  			
		 
		
		
		
		
		}
	
	/*
	after leaving the while loop, since all of the changes have been made,
	the program will now write the changes to the file.
	*/
		studentGrades.saveDLListToFile("studentlist.txt");
		
	}












}
