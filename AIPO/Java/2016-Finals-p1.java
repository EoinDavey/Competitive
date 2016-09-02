import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;


public class p1 {
	
	final int INF = (int) Math.pow(10,9);
	
	int M,N;

	public static void main(String[] args) throws IOException {
		p1 main = new p1();
		main.run();
	}
	
	void run() throws IOException{
		readIn();
		printBoard(N,M);
		stop();
	}
	
	void printBoard(int n, int m){
		 boolean astR = true;
		 for(int i = 0; i < N; i++){
			 if((i+1)%2==0)astR=false;
			 else astR =true;
			 StringBuilder sb = new StringBuilder();
			 for(int j = 0; j < M; j++){
				 if(astR)sb.append('*');
				 else sb.append('.');
				 astR=!astR;
			 }
			 print(sb.toString());
		 }
	}
	
	void readIn() throws IOException{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String in;
		st=new StringTokenizer(reader.readLine());
		N=Integer.parseInt(st.nextToken());
		M=Integer.parseInt(st.nextToken());
		reader.close();
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

