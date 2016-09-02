import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Random;
import java.util.StringTokenizer;

/*
ID: eoin.da1
LANG: JAVA
TASK: prefix
 */
public class C1P1{
	
	BigInteger C = BigInteger.ZERO;
	
	BigInteger A,B;
	
	public static void main(String[] args) throws IOException{
		C1P1 main = new C1P1();
		main.run();
	}
	
	public void run() throws IOException{
		readIn();
		search();
		stop();
	}
	
	void search(){
		BigInteger w = BigInteger.ZERO;
		int count = 0;
		for(int i = 0; i < 64; i++){
			byte[] byes = new byte[64];
			w = new BigInteger(byes);
			for(int k = 0; k < i; k++){
				w=w.setBit(k);
			}
			w=w.clearBit(i);
			for(int k = i+1; k < 64; k++){
				w=w.setBit(k);
				if((w.compareTo(A) == 1 || w.compareTo(A) == 0) && (w.compareTo(B) == -1 || w.compareTo(B) == 0)){
					count ++;
				}
			}
		}
		print(""+count);
	}
	
	private void readIn() throws IOException {
		//BufferedReader reader = new BufferedReader(new FileReader("prefix.in"));
		//out = new PrintWriter(new BufferedWriter(new FileWriter("prefix.out")));
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String in;
		
		st=new StringTokenizer(reader.readLine());
		A=new BigInteger(st.nextToken());
		B=new BigInteger(st.nextToken());
		
	}
	
	
	private void print(String s){
		System.out.println(s);
	}
	
	void stop(){
		
	}
}
