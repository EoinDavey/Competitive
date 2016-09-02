import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
/*
ID: eoin.da1
LANG: JAVA
PROG: dualpal
 */

class dualpal {
	public static void main(String[] args) throws IOException{
		Scanner scanner = new Scanner(new FileReader("dualpal.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("dualpal.out")));
		int N = scanner.nextInt();
		long S = scanner.nextInt() + 1;
		int count = 0;
		int nCount;
		while(count < N){
			nCount = 0;
			for(int i = 1; i < 10; i++){
				if(isPalindrome(changeBase(S,i+1))){
					nCount++;
				}
			}
			if(nCount >= 2){
				count++;
				out.println(S);
			}
			S++;
		}
		out.close();
	}
	
	public static boolean isPalindrome(String input){
		StringBuilder sb = new StringBuilder(input);
		String rev = sb.reverse().toString();
		if(input.equals(rev)){
			return true;
		}
		return false;
	}
	
	public static String changeBase(long N, int base){
		return Long.toString(N,base);
	}
}