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
import java.util.StringTokenizer;

/*
ID: eoin.da1
LANG: JAVA
TASK: comehome
*/

public class comehome {
	
	PrintWriter out;
	
	int N;
	int[] dist;
	char[] az = {'a','b','c','d','e','f','g','h','i','j','k','l','m'
			,'n','o','p','q','r','s','t','u','v','w','x','y','z'
			,'A','B','C','D','E','F','G','H','I','J','K','L','M','N'
			,'O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	ArrayList<int[]>[] adjList;
	ArrayList<Integer> cows = new ArrayList<Integer>();
	
	final int INF = (int) Math.pow(10, 9);
	
	public static void main(String[] args) throws IOException{
		comehome main = new comehome();
		main.run();
	}
	
	public void run()throws IOException{
		readIn();
		dijsktra();
		process();
		stop();
	}
	
	void process(){
		int min = Integer.MAX_VALUE;
		int minPos=0;
		for(int i = 0; i < cows.size(); i++){
			int val = dist[cows.get(i)];
			if(val<min){
				min=val;
				minPos=cows.get(i);
			}
		}
		print(Character.toUpperCase(az[minPos]) + " " + min);
	}
	
	void dijsktra(){
		PriorityQueue<Edge> q = new PriorityQueue<Edge>();
		dist = new int[52];
		Arrays.fill(dist, INF);
		dist[25] = 0;
		q.offer(new Edge(0,25));
		Edge c;
		int d, u, v, newD;
		int[] in;
		while(!q.isEmpty()){
			c = q.poll();
			d = c.d;
			u = c.u;
			for(int i = 0; i < adjList[u].size();i++){
				in = adjList[u].get(i);
				v = in[0];
				newD = in[1]+d;
				if(newD < dist[v]){
					dist[v] = newD;
					q.offer(new Edge(dist[v],v));
				}
			}
		}
	}
	
	int charPos(char c){
		return Arrays.binarySearch(az, c);
	}
	
	
	void readIn() throws IOException{
		BufferedReader reader = new BufferedReader(new FileReader("comehome.in"));
		out = new PrintWriter(new FileWriter("comehome.out"));
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String in;
		adjList = new ArrayList[52];
		for(int i = 0; i < adjList.length;i++){
			adjList[i] = new ArrayList<int[]>();
		}
		Arrays.sort(az);
		int n = Integer.parseInt(reader.readLine());
		for(int i = 0; i < n; i++){
			st=new StringTokenizer(reader.readLine());
			char u = st.nextToken().charAt(0);
			char v = st.nextToken().charAt(0);
			int d =Integer.parseInt(st.nextToken());
			int ux = charPos(u);
			int vx = charPos(v);
			adjList[ux].add(new int[]{vx,d});
			adjList[vx].add(new int[]{ux,d});
			if(Character.isUpperCase(u)&&u!='Z'){
				cows.add(ux);
			}
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
	int u,d;
	Edge(int d, int u){
		this.u = u;
		this.d = d;
	}
	@Override
	public int compareTo(Edge e) {
		if(this.d<e.d) return -1;
		else if (this.d > e.d) return 1;
		else return 0;
	}
}