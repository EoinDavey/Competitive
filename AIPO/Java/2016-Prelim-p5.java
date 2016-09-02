import java.util.*;
import java.lang.*;
import java.io.*;

class p5
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner scanner = new Scanner(new InputStreamReader(System.in));
		int n = scanner.nextInt();
		int[] rates = new int[n];
		for(int i = 0; i < n; i++){
			rates[i] = scanner.nextInt();
		}
		int result,temp;
		result=temp=0;
		for(int i = 0; i<n;i++){
			for(int j = i; j<n;j++){
				temp = rates[j]-rates[i];
				if(temp > result) result = temp;
			}
		}
		System.out.println(result);
	}
}