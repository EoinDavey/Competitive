import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Stack;
import java.util.StringTokenizer;
/*
ID: eoin.da1
LANG: JAVA
PROG: holstein
 */

class holstein {
	PrintWriter out;
	int V, G, minScoops, minSum;
	int[] vRequirements;
	int[] current;
	int[][] vFood;
	boolean[] used;
	boolean[] winnerCombo;
	
	public static void main(String[] args) throws IOException{
		holstein main = new holstein();
		main.run();
	}
	
	public void run() throws IOException{
		readIn();
		tryCombos(0,0);
		printResult();
	}
	
	void process(boolean[] in){
		boolean[] temp = new boolean[in.length];
		for(int i = 0; i < temp.length;i++){
			temp[i] = in[i];
		}
		int scoops, sum;
		scoops=sum=0;
		for(int j=0; j < temp.length; j++){
			if(temp[j] == true){
				scoops++;
				sum += j;
			}
		}
		if(scoops < minScoops){
			minScoops = scoops;
			minSum = sum;
			winnerCombo = temp;
		} else if(scoops == minScoops){
			if(sum < minSum){
				minSum = sum;
				winnerCombo = temp;
			}
		}
	}
	
	private boolean tryCombos(int at, int start) {
		if(at > minScoops) return true;
		if(isComplete()){
			process(used);
			return true;
		}
		for(int i = start; i < G; i++){
			if(!used[i]){
				used[i] = true;
				for(int j = 0; j < V;j++){
					current[j] = current[j] + vFood[i][j];
				}
				boolean b = tryCombos(at+1, i);
				for(int j = 0; j < V;j++){
					current[j] = current[j] - vFood[i][j];
				}
				used[i] = false;
				if(b) break;
			}
		}
		return false;
	}

	boolean isComplete(){
		for(int i = 0; i < vRequirements.length;i++){
			if(current[i] < vRequirements[i]){
				return false;
			}
		}
		return true;
	}

	private void readIn() throws IOException {
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader reader = new BufferedReader(new FileReader("holstein.in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter("holstein.out")));
		StringTokenizer st;
		minScoops = minSum = Integer.MAX_VALUE;
		V = Integer.parseInt(reader.readLine());
		vRequirements = new int[V];
		current = new int[V];
		st = new StringTokenizer(reader.readLine());
		for(int i = 0; i < V; i++){
			vRequirements[i] = Integer.parseInt(st.nextToken());
		}
		G = Integer.parseInt(reader.readLine());
		used = new boolean[G];
		vFood = new int[G][V];
		for(int i = 0; i < G; i++){
			st = new StringTokenizer(reader.readLine());
			for(int j = 0; j< V;j++){
				vFood[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		reader.close();
	}
	
	private void printResult(){
		out.print(minScoops + " ");
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < winnerCombo.length; i++){
			if(winnerCombo[i]) sb.append((i+1) + " ");
		}
		sb.deleteCharAt(sb.length()-1);
		out.println(sb.toString());
		out.close();
	}
}