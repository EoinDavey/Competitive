import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;


public class p3 {
	
	final int INF = (int) Math.pow(10,9);
	
	int N,M;
	boolean[][] grid;

	public static void main(String[] args) throws IOException {
		p3 main = new p3();
		main.run();
	}
	
	void run() throws IOException{
		readIn();
		procGrid();
		stop();
	}
	
	void procGrid(){
		int max,count;
		max=count=0;
		//for each row
		for(int i = 0; i < N; i++){
			count = solve(i);
			if(count>max)max=count;
		}
		print(""+max);
	}
	
	int solve(int n){
		int count = 0;
		//count matching rows
		for(int i = 0; i < N; i++){
			boolean valid = true;
			for(int j = 0; j<M;j++){
				if(grid[i][j]!=grid[n][j]){
					valid = false;
					break;
				}
			}
			if(valid) count++;
		}
		return count;
	}
	
	void readIn() throws IOException{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String in;
		
		st=new StringTokenizer(reader.readLine());
		N=Integer.parseInt(st.nextToken());
		M=Integer.parseInt(st.nextToken());
		grid = new boolean[N][M];
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M;j++){
				char c = (char) reader.read();
				//harp -> true
				//tails -> false
				grid[i][j] = (c=='H') ? true:false;
			}
			reader.readLine();
		}
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

