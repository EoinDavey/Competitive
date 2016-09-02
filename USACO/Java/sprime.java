import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.BitSet;
import java.util.StringTokenizer;
/*
ID: eoin.da1
LANG: JAVA
PROG: sprime
 */

class sprime {
	PrintWriter out;
	int N;
	boolean[] marked;
	boolean[] prime;
	int currentNum = 0;
	public static void main(String[] args) throws IOException{
		sprime main = new sprime();
		main.run();
	}
	
	public void run() throws IOException{
		readIn();
		//fillPrimeArray();
		genSuperPrimes();
		printResult();
	}
	
	boolean isPrime(int n){
		if(n==1) return false;
		int sqrt = (int) Math.sqrt(n);
		for(int i = 2; i<=sqrt;i++){
			if(n%i==0) return false;
		}
		return true;
	}
	
	private void genSuperPrimes() {
		String in = Integer.toString(currentNum);
		if(currentNum == 0){
			in="";
		}
		if(in.length() == N){
			out.println(in);
			return;
		}
		for(int i = 1; i <= 9; i++){
			currentNum = Integer.parseInt(in+i);
			if(isPrime(currentNum)){
				genSuperPrimes();
			}
		}
		if(in.equals("")) return;
		currentNum = Integer.parseInt(in);
	}

	private void fillPrimeArray() {
		marked = new boolean[10000];
		prime = new boolean[10000];
		for(int i = 2; i < 10000; i++){
			if(!marked[i]){
				int mult = 1;
				prime[i] = true;
				while(i*mult < 10000){
					marked[i*mult] = true;
					mult++;
				}
			}
		}
	}

	private void readIn() throws IOException {
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader reader = new BufferedReader(new FileReader("sprime.in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter("sprime.out")));
		N = Integer.parseInt(reader.readLine());
		reader.close();
	}
	
	private void printResult(){
		out.close();
	}
}