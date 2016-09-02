import java.util.*;
import java.lang.*;
import java.io.*;

class p1
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner scanner = new Scanner(new InputStreamReader(System.in));
		boolean in1,in2,result;
		String[] line = scanner.nextLine().split(" ");
		if(line[0].equals("true")) in1 = true;
		else in1 = false;
		if(line[2].equals("true")) in2 = true;
		else in2 = false;
		if(line[1].equals("AND")) result = in1 && in2;
		else result = in1 || in2;
		System.out.println(result);
	}
}