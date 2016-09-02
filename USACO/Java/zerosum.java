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
TASK: zerosum
*/

public class zerosum {
	
	PrintWriter out;
	int N;
	char[] c;
	List<String> results = new ArrayList<String>();
	
	public static void main(String[] args) throws IOException{
		zerosum main = new zerosum();
		main.run();
	}
	
	public void run()throws IOException{
		readIn();
		backtrack(1);
		printResults();
	}
	
	private void printResults() {
		Collections.sort(results);
		for(int i = 0; i < results.size(); i++){
			print(results.get(i));
		}
		out.close();
	}

	void readIn() throws IOException{
		BufferedReader reader = new BufferedReader(new FileReader("zerosum.in"));
		out = new PrintWriter(new FileWriter("zerosum.out"));
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String in;
		N = Integer.parseInt(reader.readLine());
		c = new char[N];
		c[0] = '+';
	}
	
	void backtrack(int depth){
		if(depth == N){
			check();
			return;
		}
		c[depth]='+';
		backtrack(depth+1);
		c[depth]='-';
		backtrack(depth+1);
		c[depth]=' ';
		backtrack(depth+1);
	}
	
	void check(){
		int sum = 0;
		String carry="";
		for(int i = N-1; i >=0; i--){
			carry = (i+1) + carry;
			if(c[i] == ' '){
			} else if(c[i] == '+'){
				sum += Integer.parseInt(carry);
				carry="";
			} else if(c[i]=='-'){
				sum-=Integer.parseInt(carry);
				carry="";
			}
		}
		if(sum==0){
			print();
		}
	}
	
	void print(){
		StringBuilder sb = new StringBuilder();
		for(int i = 1; i <N; i++){
			sb.append(""+ i + c[i]);
		}
		sb.append(""+N);
		results.add(sb.toString());
	}
	
	void print(String s){ 
		out.println(s);
	}
}
