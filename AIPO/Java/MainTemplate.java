import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;


public class Main {
	
	final int INF = (int) Math.pow(10,9);
	
	int N;

	public static void main(String[] args) throws IOException {
		Main main = new Main();
		main.run();
	}
	
	void run() throws IOException{
		readIn();
		stop();
	}
	
	void readIn() throws IOException{
		//Scanner scanner = new Scanner(System.in);
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String in;
		
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

