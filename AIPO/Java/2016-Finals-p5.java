import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;


public class p5 {
	
	final int INF = (int) Math.pow(10,9);
	
	int N,T,M;
	boolean[][] adjMat; //Adjacency Matrix, the boolean at [i,j] is true if i & j are connected
	boolean[] visited;

	public static void main(String[] args) throws IOException {
		p5 main = new p5();
		main.run();
	}
	
	void run() throws IOException{
		readIn();
		stop();
	}
	
	void checkIsTree(){
		//flood fill to check if tree is disconnected
		boolean tree = true;
		floodFill(1);
		for(int i = 1; i < visited.length; i++){
			if(!visited[i]){
				tree = false;
				break;
			}
		}
		if(!tree){
			print("graph"); 
			return;
		}
		//articulation points
		/*
		remove each edge one at a time and see if tree is disconnected. If it's still connected a cycle exists.
		*/
		boolean art;
		for(int i = 1; i <=N; i++){
			if(!tree) break;
			for(int j = i+1; j <=N; j++){
				if(!adjMat[i][j]) continue;
				visited = new boolean[N+1]; //size is N+1 as nodes are not 0 indexed
				art=false;
				adjMat[i][j]=adjMat[j][i]=false; //remove connection both ways
				floodFill(1); //visit everything reachable from 1.
				for(int k = 1; k < visited.length; k++){
					if(!visited[k]){
						//disconnected, still a tree.
						art = true;
						break;
					}
				}
				if(!art){
					//still connected, not a tree
					tree = false;
					break;
				}
			}
		}
		if(!tree){
			print("graph");
		} else print("tree");
	}
	
	void floodFill(int i){
		//recursively visit everything and mark it visited
		visited[i]=true;
		for(int j = 1; j <= N; j++){
			if(adjMat[i][j]&&!visited[j]){
				floodFill(j);
			}
		}
	}
	
	void readIn() throws IOException{
		//Scanner scanner = new Scanner(System.in);
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String in;
		
		T=Integer.parseInt(reader.readLine());
		for(int t = 0; t < T; t++){
			N=Integer.parseInt(reader.readLine());
			M=Integer.parseInt(reader.readLine());
			if(M!=N-1){ //In a tree the number of edges is the number of nodes - 1;
				print("graph");
				for(int i = 0; i < M; i++){
					reader.readLine();
				}
				continue;
			}
			adjMat = new boolean[N+1][N+1];
			visited=new boolean[N+1];
			int a,b;
			boolean doubleEdge = false; //boolean to check if an edge is added twice
			for(int i = 0; i < M; i++){
				st = new StringTokenizer(reader.readLine());
				a=Integer.parseInt(st.nextToken());
				b=Integer.parseInt(st.nextToken());
				if(adjMat[a][b]) doubleEdge = true;
				adjMat[a][b]=adjMat[b][a]=true;
			}
			if(!doubleEdge)	checkIsTree();
			else print("graph");
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

