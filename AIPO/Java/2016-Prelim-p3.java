import java.util.*;
import java.lang.*;
import java.io.*;
 
class p3
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner scanner = new Scanner(new InputStreamReader(System.in));
		int n = scanner.nextInt();
		collatz(n);
	}
	private static void collatz(int n){
		System.out.print(Integer.toString(n) + " ");
		if(n==1){
			return;
		} else if(n % 2 == 0){
			collatz(n/2);
		} else {
			collatz((3*n) + 1);
		}
	}
}