import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
/*
ID: eoin.da1
LANG: JAVA
PROG: namenum
 */

class namenum {
	static ArrayList<String> dictList;
	static String[] dict;
	static int sum = 0;
	static PrintWriter out;
	static boolean printed = false;
	public static void main(String[] args) throws IOException{
		out = new PrintWriter(new BufferedWriter(new FileWriter("namenum.out")));
		Scanner scanner = new Scanner(new FileReader("dict.txt"));
		dictList = new ArrayList<String>();
		while(scanner.hasNextLine()){
			dictList.add(scanner.nextLine());
		}
		dict = new String[dictList.size()];
		dict = dictList.toArray(dict);
		//scanner = new Scanner(System.in);
		scanner = new Scanner(new FileReader("namenum.in"));
		long N = scanner.nextLong();
		char[] digits = Long.toString(N).toCharArray();
		loop(digits,0,new char[digits.length]);
		if(!printed){
			out.println("NONE");
		}
		out.close();
	}
	
	static void loop(char[] digits,int n, char[] result){
		if(n == digits.length){
			//out.println(new String(result));
			if(Arrays.binarySearch(dict, new String(result)) > 0){
				printed = true;
				out.println(new String(result));
			}
			return;
		}
		int numChar = Character.getNumericValue(digits[n]);
		int start = (int)'A';
		start += (numChar - 2) * 3;
		if(numChar > 7){
			start ++;
		}
		result[n] = (char) start;
		loop(digits, n+1, result);
		start ++;
		if(Character.getNumericValue(digits[n]) == 7){
			start++;
		}
		result[n] = (char) start;
		loop(digits, n+1, result);
		start ++;
		result[n] = (char) start;
		loop(digits, n+1, result);
	}
}