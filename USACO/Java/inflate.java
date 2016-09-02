import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Stack;
import java.util.StringTokenizer;

/*
ID: eoin.da1
LANG: JAVA
TASK: inflate
*/

public class inflate {
	
	PrintWriter out;
	
	int M,N;
	int[] dp;
	int[] W,V;
	
	final int INF = (int) Math.pow(10, 9);
	
	public static void main(String[] args) throws IOException{
		inflate main = new inflate();
		main.run();
	}
	
	public void run()throws IOException{
		readIn();
		print(""+dp());
		stop();
	}
	
	//bottom up
	int dp(){
		dp = new int[M+1];
		for(int i = 0; i <=M;i++){
			dp[i] = 0;
		}
		int v,w,prevPos,prev; 
		for(int j = 0; j < N; j++){
			v=V[j];
			w=W[j];
			for(int i = w; i <=M;i++){
				prevPos = i-w;
				prev=0;
				if(prevPos>=0) prev = v + dp[prevPos];
				dp[i] = (prev>dp[i])? prev:dp[i];
			}
		}
		return dp[M];
	}
	
	void readIn() throws IOException{
		BufferedReader reader = new BufferedReader(new FileReader("inflate.in"));
		out = new PrintWriter(new FileWriter("inflate.out"));
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String in;
		st=new StringTokenizer(reader.readLine());
		M=Integer.parseInt(st.nextToken());
		N=Integer.parseInt(st.nextToken());
		W=new int[N];
		V=new int[N];
		for(int i = 0; i < N; i++){
			st = new StringTokenizer(reader.readLine());
			V[i]=Integer.parseInt(st.nextToken());
			W[i]=Integer.parseInt(st.nextToken());
		}
		//for(int i = 0; i < N; i++){
		//	Arrays.fill(memo[i], -1);
		//}
	}
	
	void stop(){
		out.close();
	}
	
	void print(String s){
		out.println(s);
	}
}


