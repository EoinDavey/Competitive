import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Stack;
import java.util.StringTokenizer;


public class p2 {
	
	final int INF = (int) Math.pow(10,9);
	
	long I,J;

	public static void main(String[] args) throws IOException {
		p2 main = new p2();
		main.run();
	}
	
	void run() throws IOException{
		readIn();
		print(""+lcm(I,J));
		stop();
	}
	
	void readIn() throws IOException{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String in;
		st = new StringTokenizer(reader.readLine());
		I=Long.parseLong(st.nextToken());
		J=Long.parseLong(st.nextToken());
		reader.close();
	}
	
	long lcm(long i, long j){
		return i*(j/gcd(i,j));
	}
	
	long gcd(long i, long j){
		return (j==0) ? i:gcd(j,i%j);
	}
	
	void stop(){
		
	}
	
	double toRadians(double deg){
		return deg*(Math.PI/180);
	}
	
	void print(String s){
		System.out.println(s);
	}

}

