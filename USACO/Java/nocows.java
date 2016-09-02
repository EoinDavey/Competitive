import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

/*
ID: eoin.da1
LANG: JAVA
TASK: nocows
 */
class nocows {
	
	PrintWriter out;
	int N,K;
	BigInteger store[][] = new BigInteger[201][201];
	
	public static void main(String[] args) throws IOException{
		nocows main = new nocows();
		main.run();
	}
	
	public void run() throws IOException{
		readIn();
		print("" + 					process(N,K).subtract(process(N,K-1)).mod(BigInteger.valueOf(9901))					);
		stop();
	}
	
	private BigInteger process(int n, int k) {
		BigInteger sum=BigInteger.ZERO;
		if(k==0||n==0) return BigInteger.ZERO;
		if(n==1) return BigInteger.ONE;
		if(!store[n][k].equals(BigInteger.valueOf(-1))) return store[n][k];
		for(int i = 0; i<n-1;i++){
			sum=sum.add(process(i,k-1).multiply(process(n-i-1,k-1)));
		}
		return store[n][k]=sum;
	}
	
	private void readIn() throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader("nocows.in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter("nocows.out")));
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String in;
		st = new StringTokenizer(reader.readLine());
		N=Integer.parseInt(st.nextToken());
		K=Integer.parseInt(st.nextToken());
		for(int i = 0; i <201;i++){
			Arrays.fill(store[i], BigInteger.valueOf(-1));
		}
	}
	
	private void print(String s){
		out.println(s);
	}
	
	void stop(){
		out.close();
	}
}