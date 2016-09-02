import java.util.*;
import java.lang.*;
import java.io.*;

class p2
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner scanner = new Scanner(new InputStreamReader(System.in));
		String in = scanner.nextLine();
		String rev = new StringBuilder(in).reverse().toString();
		if(in.equals(rev)){
			System.out.println("true");
		} else {
			System.out.println("false");
		}
	}
}