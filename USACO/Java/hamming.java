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
PROG: hamming
 */

class hamming {
	PrintWriter out;
	int N,B,D;
	ArrayList<Integer> current = new ArrayList<Integer>();
	
	public static void main(String[] args) throws IOException{
		hamming main = new hamming();
		main.run();
	}
	
	public void run() throws IOException{
		readIn();
		//hamiltonTest();
		loop(0,0);
		printResult();
	}
	
	void hamiltonTest(){
		out.println(hammingDistance(7, 14));
	}
	
	private boolean loop(int start, int level){
		if(level >= N){
			return true;
		}
		for(int i = start; i < Math.pow(2, B);i++){
			if(isValid(i)){
				current.add(i);
				if(loop(i, level+1)){
					return true;
				}
				current.remove(current.size()-1);
			}
		}
		return false;
	}
	
	boolean isValid(int in){
		for(int i = 0; i < current.size();i++){
			if(hammingDistance(current.get(i),in) < D){
				return false;
			}
		}
		return true;
	}

	int hammingDistance(int in1,int in2){
		int sum = 0;
		String s = Integer.toBinaryString(in1^in2);
		for(int i = 0; i < s.length(); i++){
			if(s.charAt(i) == '1'){
				sum++;
			}
		}
		return sum;
	}
	
	private void readIn() throws IOException {
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader reader = new BufferedReader(new FileReader("hamming.in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter("hamming.out")));
		StringTokenizer st = new StringTokenizer(reader.readLine());
		N=Integer.parseInt(st.nextToken());
		B=Integer.parseInt(st.nextToken());
		D=Integer.parseInt(st.nextToken());
		reader.close();
	}
	
	private void printResult(){
		if(current.size() == 0) return;
		int count = 0;
		int i = 0;
		while(i<current.size()-1){
			int n = current.get(i);
			i++;
			count++;
			if(count == 10){
				out.println(n);
				count = 0;
			} else {
				out.print(n + " ");
			}
		}
		out.println(current.get(current.size()-1));
		out.close();
	}
}