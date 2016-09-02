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
PROG: subset
 */

class subset {
	PrintWriter out;
	int N;
	float limit;
	float half;
	long[][] cache;
	long sum = 0;
	public static void main(String[] args) throws IOException{
		subset main = new subset();
		main.run();
	}
	
	public void run() throws IOException{
		readIn();
		calculateLimit();
		sum = loop((int) half, N);
		printResult();
	}
	
	private long loop(int n, int k) {
		if(n<0||k<0){
			return 0;
		} else if(k==0&&n==0){
			return 1;
		} else if(cache[n][k]!=-1) return cache[n][k];
		return cache[n][k] = loop(n,k-1) + loop(n-k,k-1);
	}

	private void calculateLimit() {
		float half1 = (float)N /2;
		limit = half1*(2+(N-1));
		if(limit%2!=0){
			printResult();
			System.exit(0);
		}
		half = limit/2;
		cache = new long[(int) half+1][N+1];
		for(int i = 0; i < cache.length; i++){
			Arrays.fill(cache[i], -1);
		}
	}

	private void readIn() throws IOException {
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader reader = new BufferedReader(new FileReader("subset.in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter("subset.out")));
		N=Integer.parseInt(reader.readLine());
		reader.close();
	}
	
	private void printResult(){
		out.println(sum/2);
		out.close();
	}
}