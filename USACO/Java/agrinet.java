import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Stack;
import java.util.StringTokenizer;

/*
ID: eoin.da1
LANG: JAVA
TASK: agrinet
*/

public class agrinet {
	
	PrintWriter out;
	
	int N;
	int[][] plane;
	
	final int INF = (int) Math.pow(10, 9);
	
	public static void main(String[] args) throws IOException{
		agrinet main = new agrinet();
		main.run();
	}
	
	public void run()throws IOException{
		readIn();
		prims();
		stop();
	}
	
	void prims(){
		PriorityQueue<Edge> q = new PriorityQueue<Edge>();
		Edge c;
		int d,u;
		int mst = 0;
		boolean[] visited = new boolean[N];
		visited[0] = true;
		for(int i = 0; i < plane[0].length;i++){
			if(plane[0][i]==0)continue;
			q.offer(new Edge(plane[0][i],i));
		}
		while(!q.isEmpty()){
			c=q.poll();
			d = c.d;
			u = c.u;
			if(visited[u]) continue;
			mst+=d;
			visited[u] = true;
			for(int i = 0; i < plane[u].length;i++){
				int newD = plane[u][i];
				if(newD!=0&&visited[i]==false){
					q.offer(new Edge(newD,i));
				}
			}
		}
		print(""+mst);
	}
	
	void readIn() throws IOException{
		BufferedReader reader = new BufferedReader(new FileReader("agrinet.in"));
		out = new PrintWriter(new FileWriter("agrinet.out"));
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String in;
		N=Integer.parseInt(reader.readLine());
		plane = new int[N][N];
		st=new StringTokenizer(reader.readLine());
		int rowCount = 0;
		int colCount=0;
		while(true){
			plane[rowCount][colCount] = Integer.parseInt(st.nextToken());
			colCount++;
			if(colCount>=N){
				colCount=0;
				rowCount++;
				if(rowCount>=N){
					break;
				}
			}
			if(!st.hasMoreTokens())st=new StringTokenizer(reader.readLine());
		}
	}
	
	void stop(){
		out.close();
	}
	
	void print(String s){
		out.println(s);
	}
}
class Edge implements Comparable<Edge>{
	int d,u;
	Edge(int d, int u){
		this.d=d;
		this.u=u;
	}
	
	@Override
	public int compareTo(Edge arg0) {
		if(this.d<arg0.d)return -1;
		if(this.d>arg0.d)return 1;
		return 0;
	}
}

