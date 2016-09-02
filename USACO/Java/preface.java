import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Stack;
import java.util.StringTokenizer;
/*
ID: eoin.da1
LANG: JAVA
PROG: preface
 */

class preface {
	PrintWriter out;
	int N;
	int[] count = new int[7];
	char[] chars = {'I','V','X','L','C','D','M'};
	public static void main(String[] args) throws IOException{
		preface main = new preface();
		main.run();
	}
	
	public void run() throws IOException{
		readIn();
		loop();
		//getRomNum(N);
		printResult();
	}
	
	void loop(){
		for(int i = 0; i <= N; i++){
			String rom = roman(i);
			if(rom==null) continue;
			for(int j = 0; j < rom.length(); j++){
				addToResult(rom.charAt(j));
			}
		}
	}
	
	private String roman(int n) {
		String in = Integer.toString(n);
		String result = "";
		for(int i = 0; i<in.length();i++){
			result += getRomNum(in.charAt(i), in.length()-1-i);
		}
		return result;
	}

	private String getRomNum(char val, int pow) {
		char one,five,ten;
		one=five=ten='A';
		String result="";
		switch(pow){
		case 0:
			one = 'I';
			five = 'V';
			ten = 'X';
			break;
		case 1:
			one = 'X';
			five = 'L';
			ten = 'C';
			break;
		case 2:
			one = 'C';
			five = 'D';
			ten = 'M';
			break;
		case 3:
			one = 'M';
			break;	
		}
		switch(val){
		case '1':
			result = result + one;
			break;
		case '2':
			result = result + one + one;
			break;
		case '3':
			result = result + one + one + one;
			break;
		case '4':
			result = result + one + five;
			break;
		case '5':
			result = result + five;
			break;
		case '6':
			result= result + five+one;
			break;
		case '7':
			result = result + five+one+one;
			break;
		case '8':
			result = result + five+one+one+one;
			break;
		case '9':
			result = result + one + ten;
			break;
		}
		return result;
	}
	
	private void addToResult(char charAt) {
		switch(charAt){
		case 'I':
			count[0]++;
			break;
		case 'V':
			count[1]++;
			break;
		case 'X':
			count[2]++;
			break;
		case 'L':
			count[3]++;
			break;
		case 'C':
			count[4]++;
			break;
		case 'D':
			count[5]++;
			break;
		case 'M':
			count[6]++;
			break;
		}
	}

	private void readIn() throws IOException {
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader reader = new BufferedReader(new FileReader("preface.in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter("preface.out")));
		N = Integer.parseInt(reader.readLine());
		reader.close();
	}
	
	private void printResult(){
		for(int i = 0; i < count.length;i++){
			if(count[i]==0) continue;
			out.println(chars[i] + " " + count[i]);
		}
		out.close();
	}
}