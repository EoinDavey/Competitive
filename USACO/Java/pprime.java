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
PROG: pprime
 */

class pprime {
	PrintWriter out;
	int A,B;
	public static void main(String[] args) throws IOException{
		pprime main = new pprime();
		main.run();
	}
	
	public void run() throws IOException{
		readIn();
		generatePalindromes();
		printResult();
	}
	
	private void generatePalindromes() {
		int length = Integer.toString(B).length();
		int current;
		//1-10
		for(int i = A; i < Math.min(10, B); i++){
			if(i==1||i==0){
				continue;
			}
			isPrime(i);
		}
		if(length<2) return;
		//1-100
		for(int d1 = 1; d1 < 10; d1++){
			current = d1*10 + d1;
			if(current >= A && current <= B){
				isPrime(current);
			}
		}
		//1-1000
		if(length<3) return;
		for(int d1 = 1; d1 < 10; d1++){
			for(int d2=0;d2<10;d2++){
				current = d1*100 + d2*10 + d1;
				if(current >= A && current <= B){
					isPrime(current);
				}
			}
		}
		//1-10000
		if(length<4) return;
		for(int d1 = 1; d1 < 10; d1++){
			for(int d2=0;d2<10;d2++){
				current = d1*1000 + d2*100 + d2*10 + d1;
				if(current >= A && current <= B){
					isPrime(current);
				}
			}
		}
		//1-100000
		if(length<5) return;
		for(int d1 = 1; d1 < 10; d1++){
			for(int d2=0;d2<10;d2++){
				for(int d3=0; d3<10; d3++){
					current = d1*10000 + d2*1000 + d3*100 + d2*10 + d1;
					if(current >= A && current <= B){
						isPrime(current);
					}
				}
			}
		}
		//1-1000000
		if(length<6) return;
		for(int d1 = 1; d1 < 10; d1++){
			for(int d2=0;d2<10;d2++){
				for(int d3=0; d3<10; d3++){
					current = d1*100000 + d2*10000 + d3*1000 + d3 * 100 + d2*10 + d1;
					if(current >= A && current <= B){
						isPrime(current);
					}
				}
			}
		}
		//1-100000000 
		if(length<7) return;
		for(int d1 = 1; d1 < 10; d1++){
			for(int d2=0;d2<10;d2++){
				for(int d3=0; d3<10; d3++){
					for(int d4=0;d4<10;d4++){
						current = d1*1000000 + d2*100000 + d3*10000 + d4*1000 + d3 * 100 + d2*10 + d1;
						if(current >= A && current <= B){
							isPrime(current);
						}
					}
				}
			}
		}
	}

	private void isPrime(int j) {
		int sqrt =(int) Math.sqrt(j);
		for(int i = 2; i <= sqrt;i++){
			if(j%i==0){
				return;
			}
		}
		out.println(j);
	}

	private void readIn() throws IOException {
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader reader = new BufferedReader(new FileReader("pprime.in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter("pprime.out")));
		StringTokenizer st;
		st = new StringTokenizer(reader.readLine());
		A = Integer.parseInt(st.nextToken());
		B = Integer.parseInt(st.nextToken());
		reader.close();
	}
	
	private void printResult(){
		out.close();
	}
}