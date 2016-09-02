import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

	PrintWriter out;
	public static void main(String[] args) throws IOException{
		Main main = new Main();
		main.run();
	}
	
	public void run()throws IOException{
		readIn();
	}
	
	void readIn() throws IOException{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int n = Integer.parseInt(reader.readLine());
		int max = 0;
		for(int i = 0; i < n; i++){
			max=0;
			String[] in = reader.readLine().split(" ");
			for(int j = 0; j < in.length; j++){
				max = Math.max(max, Integer.parseInt(in[j]));
			}
			print("Case " + (i+1) + ": " + max);
		}
	}
	
	void print(String s){ 
		System.out.println(s);
	}
}
