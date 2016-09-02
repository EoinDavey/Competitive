import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
/*
ID: eoin.da1
LANG: JAVA
PROG: palsquare
 */

class palsquare {
	static int B;
	public static void main(String[] args) throws IOException{
		//Scanner scanner = new Scanner(System.in);
		Scanner scanner = new Scanner(new FileReader("palsquare.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("palsquare.out")));
		int B = scanner.nextInt();
		for(int i = 1; i < 300; i++){
			String digits = changeBase(i*i, B);
			//System.out.println("In: " + i + " Digits: " + digits);
			if(isPalindrome(digits)){
				out.println(changeBase(i,B) + " " + digits);
			}
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
	
	public static String changeBase(int n, int newBase){
		StringBuilder sb = new StringBuilder();
		int maxPower = 0;
		while(n > Math.pow(newBase, maxPower+1)){
			maxPower++;
		}
		double row, value;
		for(int i = maxPower; i >= 0; i--){
			row = (long) Math.pow(newBase, i);
			value = Math.floor(n/row);
			if(value > 9){
				sb.append(fixValue(value));
			} else {
				sb.append((int) value);
			}
			n -= value * row;
		}
		return sb.toString();
	}
	
	public static String fixValue(double value){
		int start = (int) 'A';
		start += value - 10;
		char c = (char) start;
		return Character.toString(c);
	}
}