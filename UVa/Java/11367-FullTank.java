import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

/*
ID: eoin.da1
LANG: JAVA
TASK: prefix
 */
class Main {
	
	PrintWriter out;
	int N,M;
	int[] p;
	int[][] weight;
	int[][] dist;
	final int INF = 200;
	
	public static void main(String[] args) throws IOException{
		Main main = new Main();
		main.run();
	}
	
	public void run() throws IOException{
		readIn();
		stop();
	}

	
	private void readIn() throws IOException {
		//BufferedReader reader = new BufferedReader(new FileReader("prefix.in"));
		//out = new PrintWriter(new BufferedWriter(new FileWriter("prefix.out")));
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(reader.readLine());
		String in;
		N=Integer.parseInt(st.nextToken());
		M=Integer.parseInt(st.nextToken());
		p = new int[N+1];
		weight = new int[N+1][N+1];
		st = new StringTokenizer(reader.readLine());
		for(int i = 0; i < N; i++){
			p[i] = Integer.parseInt(st.nextToken());
		}
		int u,v,d;
		for(int i = 0; i < M; i++){
			st=new StringTokenizer(reader.readLine());
			u= Integer.parseInt(st.nextToken());	
			v= Integer.parseInt(st.nextToken());
			d= Integer.parseInt(st.nextToken());
			weight[u][v] = d;
			weight[v][u] = d;
		}
		int q = Integer.parseInt(reader.readLine());
		int c,s,e;
		for(int i = 0; i < q; i++){
			st = new StringTokenizer(reader.readLine());
			c=Integer.parseInt(st.nextToken());
			s=Integer.parseInt(st.nextToken());
			e=Integer.parseInt(st.nextToken());
			dijsktra(s,c,e);
			int min=INF;
			for(int j = 0; j < dist[e].length; j++){
				if(dist[e][j]<min) min = dist[e][j];
			}
			if(min<INF) print(""+min);
			else print("impossible");
		}
	}
	
	private void dijsktra(int source, int cap,int end) {
		PriorityQueue<State> pq = new PriorityQueue<State>();
		dist = new int[N+1][cap+1];
		for(int i = 0; i < dist.length; i++){
			for(int j = 0; j < dist[i].length;j++){
				dist[i][j] = INF;
			}
		}
		dist[source][0] = 0;
		pq.add(new State(0,source,0));
		State current;
		int u,d,f;
		while(!pq.isEmpty()){
			current = pq.poll();
			u = current.U;
			d = current.D;
			f = current.F;
			if(u==end)
				return;
			//if(dist[u] < d) continue;
			for(int i = 0; i < weight[u].length; i++){
				if(weight[u][i] == 0) continue;
				if(f>=weight[u][i]){
					if(d<dist[i][f-weight[u][i]]) dist[i][f-weight[u][i]] = d;
					pq.add(new State(d, i, f-weight[u][i]));
				}
			}
			if(f<cap&&(d+p[u] < dist[u][f+1])){
				int newD = d+p[u];
				dist[u][f+1] = newD;
				pq.add(new State(newD,u,f+1));
			}
			/*for(int i = 0; i < weight[u].length;i++){
				if(weight[u][i]==0) continue;
				int newDist = dist[u] + weight[u][i];
				if(newDist<dist[i]){
					//dist[i] = newDist;
					//pq.add(new State(newDist,i));
				}
			}*/
		}
	}

	private void print(String s){
		System.out.println(s);
	}
	
	void stop(){
		
	}
}

class State implements Comparable<State>{
	int U,D,F;
	State(int d, int u, int f){
		U = u;
		D = d;
		F = f;
	}
	
	@Override
	public int compareTo(State p) {
		if(this.D < p.D) return -1;
		else if(this.D > p.D )return 1;
		else return 0;
	}
}