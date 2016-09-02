/*
ID: eoin.da1
LANG: JAVA
PROG: ride
*/
import java.io.*;
import java.util.*;

class ride {
  public static void main (String [] args) throws IOException {
    Scanner scanner = new Scanner(new FileReader("ride.in"));
	PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("ride.out")));
	String in1 = scanner.nextLine();
	String in2 = scanner.nextLine();
	char[] char1 = in1.toCharArray();
	char[] char2 = in2.toCharArray();
	int sum1 = 1;
	int sum2 = 1;
	int error = 'A' - 1;
	int inc = 0;
	for(int i = 0; i < in1.length(); i++){
		inc = (int) char1[i] - error;
		sum1 *= inc;
	}
	for(int i = 0; i < in2.length(); i++){
		inc = (int) char2[i] - error;
		sum2 *= inc;
	}
	if(sum1 % 47 == sum2 % 47){
		out.println("GO");
	} else {
		out.println("STAY");
	}
	out.close();
  }
}