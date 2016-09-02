import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {

	PrintWriter out;
	public static void main(String[] args) throws IOException{
		Main main = new Main();
		main.run();
	}
	
	public void run()throws IOException{
		readIn();
		printOut();
	}
	
	void readIn() throws IOException{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int n = Integer.parseInt(reader.readLine());
		for(int i = 0; i < n; i++){
			st = new StringTokenizer(reader.readLine());
			int in1 = Integer.parseInt(st.nextToken());
			int in2 = Integer.parseInt(st.nextToken());
			if(in1<in2)print("<");
			else if(in1>in2)print(">");
			else print("=");
		}
	}
	
	void print(String s){
		System.out.println(s);
	}
	
	void printOut(){
		
	}

}
