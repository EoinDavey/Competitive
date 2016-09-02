import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

/*
ID: eoin.da1
LANG: JAVA
TASK: money
*/

public class money {
	
	PrintWriter out;
	int N,V;
	int[] coins;
	long[][] memo;
	
	public static void main(String[] args) throws IOException{
		money main = new money();
		main.run();
	}
	
	public void run()throws IOException{
		readIn();
	}
	

	void readIn() throws IOException{
		BufferedReader reader = new BufferedReader(new FileReader("money.in"));
		out = new PrintWriter(new FileWriter("money.out"));
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String in;
		st = new StringTokenizer(reader.readLine());
		V=Integer.parseInt(st.nextToken());
		N=Integer.parseInt(st.nextToken());
		coins = new int[V];
		memo = new long[N+1][V+1];
		int i = 0;
		while(i<V){
			st = new StringTokenizer(reader.readLine());
			while(st.hasMoreTokens()){
				coins[i] = Integer.parseInt(st.nextToken());
				i++;
			}
		}
		for(i = 0; i <= N; i++){
			Arrays.fill(memo[i], -1);
		}
		print("" + noOfWays(N,V-1));
		out.close();
	}
	
	long noOfWays(int n, int v){
		if(n<0||v<0){
			return 0;
		}
		if(n==0){
			return 1;
		}
		if(memo[n][v]!= -1) return memo[n][v];
		long sum= noOfWays(n-coins[v],v) + noOfWays(n,v-1);
		return memo[n][v] = sum;
	}
	
	void print(String s){ 
		out.println(s);
	}
}
