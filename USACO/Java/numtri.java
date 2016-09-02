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
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.StringTokenizer;
/*
ID: eoin.da1
LANG: JAVA
PROG: numtri
 */

class numtri {
	PrintWriter out;
	int R;
	int[][] input;
	int max = 0;
	public static void main(String[] args) throws IOException{
		numtri main = new numtri();
		main.run();
	}
	
	public void run() throws IOException{
		readIn();
		traverseNetwork();
		printResult();
	}
	
	private void traverseNetwork() {
		for(int i = R-2; i > 0; i--){
			for(int j = 0; j<input[i].length; j++){
				input[i][j] = Math.max(input[i+1][j], input[i+1][j+1]) + input[i][j];
			}
		}
		max = Math.max(input[1][0], input[1][1]) + input[0][0];
	}

	
	private void readIn() throws IOException {
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader reader = new BufferedReader(new FileReader("numtri.in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter("numtri.out")));
		StringTokenizer st;
		R = Integer.parseInt(reader.readLine());
		if(R==1){
			max = Integer.parseInt(reader.readLine());;
			printResult();
			System.exit(0);
		}
		input = new int[R][];
		input[0] = new int[1];
		input[0][0] = Integer.parseInt(reader.readLine());
		for(int i = 0; i < R-1; i++){
			input[i+1] = new int[2+i];
			st = new StringTokenizer(reader.readLine());
			for(int j = 0; j<2+i;j++){
				input[i+1][j] = Integer.parseInt(st.nextToken());;
			}
		}
		reader.close();
	}
	
	private void printResult() {
		out.println(max);
		out.close();
	}
}