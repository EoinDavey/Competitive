import java.util.List;
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
PROG: runround
 */

class runround {
	PrintWriter out;
	long N;
	int[] digits;
	char[] chars;
	boolean[] visited;
	int newPos;
	boolean[]values;
	public static void main(String[] args) throws IOException{
		runround main = new runround();
		main.run();
	}
	
	public void run() throws IOException{
		readIn();
		loop();
		printResult();
	}
	
	private void loop() {
		boolean found = false;
		long current = N+1;
		while(!found){
			found = isRunAround(current);
			current++;
		}
		out.println(current-1);
		out.close();
	}

	boolean isRunAround(long in){
		chars = Long.toString(in).toCharArray();
		digits = new int[chars.length];
		visited = new boolean[chars.length];
		for(int i = 0; i < chars.length; i++){
			digits[i] = Character.getNumericValue(chars[i]);
		}
		if(!checkUnique()) return false;
		return test(rotate(0));
	}
	
	boolean checkUnique(){
		values = new boolean[10];
		for(int i = 0; i < digits.length; i++){
			if(values[digits[i]]) return false;
			if(digits[i] == 0) return false;
			values[digits[i]] = true;
		}
		return true;
	}
	
	boolean test(int in){
		if(in==0){
			visited[in]=true;
			return process();
		}
		if(visited[in]){
			return false;
		}
		visited[in] = true;
		newPos = rotate(in);
		return test(newPos);
	}
	
	private boolean process(){
		for(int i = 0; i < visited.length; i++){
			if(visited[i]==false)return false;
		}
		return true;
	}

	int rotate(int in){
		return (in+digits[in]) % chars.length;
	}
	
	private void readIn() throws IOException {
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader reader = new BufferedReader(new FileReader("runround.in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter("runround.out")));
		N = Long.parseLong(reader.readLine());
		reader.close();
	}
	
	private void printResult(){
	}
}