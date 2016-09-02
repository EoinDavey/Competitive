import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

/*
ID: eoin.da1
LANG: JAVA
TASK: concom
 */
class concom {
	
	PrintWriter out;
	ArrayList<Integer[]> adjList;
	int[][] controlIn;
	boolean[][] control;
	
	public static void main(String[] args) throws IOException{
		concom main = new concom();
		main.run();
	}
	
	public void run() throws IOException{
		readIn();
		while(proc());
		genResults();
		stop();
	}
	
	private void genResults() {
		for(int i = 0; i < 101; i ++){
			for(int j = 0; j<101; j++){
				if(i==j) continue;
				if(control[i][j]){
					print(i + " " + j);
				}
			}
		}
		out.close();
	}

	boolean proc(){
		boolean changed = false;
		for(int i = 1; i < controlIn.length; i++){
			for(int j = 1; j < controlIn[i].length; j++){
				if(controlIn[i][j]>50)continue;
				if(relax(i,j)) changed = true;
			}
		}
		return changed;
	}
	
	boolean relax(int I, int J){
		if(control[I][J])return false;
		int sum = 0;
		boolean changed = false;
		for(int i = 0; i < controlIn[I].length;i++){
			//if(I==i) continue;
			if(controlIn[I][i]>50||control[I][i]){
				sum+= controlIn[i][J];
			}
		}
		if(sum>50&&control[I][J]==false){
			control[I][J]=true;
			changed = true;
		}
		return changed;
	}

	private void readIn() throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader("concom.in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter("concom.out")));
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String in;
		int n = Integer.parseInt(reader.readLine());
		int u,v,w;
		controlIn = new int[101][101];
		control = new boolean[101][101];
		for(int i = 0; i < n; i++){
			st = new StringTokenizer(reader.readLine());
			u=Integer.parseInt(st.nextToken());
			v=Integer.parseInt(st.nextToken());
			w=Integer.parseInt(st.nextToken());
			controlIn[u][v] = w;
			if(w> 50) control[u][v] = true;
		}
		for(int i = 0; i <= 100; i++){
			controlIn[i][i] = 100;
			control[i][i] = true;
		}
	}
	
	
	private void print(String s){
		out.println(s);
	}
	
	void stop(){
		
	}
}
