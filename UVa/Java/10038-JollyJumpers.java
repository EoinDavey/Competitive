import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


class Main {
	
	boolean[] difs;
	int[] input;
	
	public static void main(String[] args) throws IOException{
		Main main = new Main();
		main.run();
	}
	
	public void run() throws IOException{
		readIn();
	}
	
	void process(){
		for(int i = 0; i < input.length-1;i++){
			int val = Math.abs(input[i]-input[i+1]);
			if(val<input.length){
				difs[val]=true;
			}
		}
		boolean valid = true;
		for(int i = 1; i < difs.length; i++){
			if(!difs[i]){
				valid = false;
				break;
			}
		}
		if(valid)print("Jolly");
		else print("Not jolly");
	}
	
	private void readIn() throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String in;
		while(true){
			in = reader.readLine();
			if(in==null||in.isEmpty()) break;
			st = new StringTokenizer(in);
			int n = Integer.parseInt(st.nextToken());
			difs = new boolean[n];
			input = new int[n];
			for(int i = 0; i < n; i++){
				input[i] = Integer.parseInt(st.nextToken());
			}
			process();
		}
	}
	
	private void print(String s){
		System.out.println(s);
	}
}