import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.StringTokenizer;

/*
ID: eoin.da1
LANG: JAVA
TASK: maze1
*/

public class maze1 {
	
	PrintWriter out;
	
	int W,H;
	char[][] board;
	int[][][] dist;
	
	final int INF = Integer.MAX_VALUE;
	
	public static void main(String[] args) throws IOException{
		maze1 main = new maze1();
		main.run();
	}
	
	public void run()throws IOException{
		readIn();
		findExits();
		process();
		stop();
	}
	
	void process(){
		int max=0;
		int min;
		for(int i = 0; i < dist[0].length;i++){
			for(int j = 0; j < dist[0][i].length;j++){
				min = Math.min(dist[0][i][j], dist[1][i][j]);
				if(min!=INF&&min>max) max = min;
			}
		}
		max++;
		print(""+max);
	}
	
	void findExits(){
		int count = 0;
		for(int i = 0; i < board.length; i++){
			if(i==0||i==board.length-1){
				for(int j = 0; j < board[i].length;j++){
					if(board[i][j]==' '){
						//exit
						if(i==board.length-1){
							bfs(i-1,j,count);
						} else if(i==0){
							bfs(i+1,j,count);
						}
						count++;
					}
				}
			}
			if(i%2==1){
				if(board[i][0]==' '){
					//exit
					bfs(i,1,count);
					count++;
				}
				if(board[i][board[i].length-1]==' '){
					//exit
					bfs(i,board[i].length-2,count);
					count++;
				}
			}
		}
	}
	
	void bfs(int sY,int sX,int layer){
		LinkedList<Edge> q = new LinkedList<Edge>();
		dist[layer][sY][sX] = INF;
		q.add(new Edge(0,sY,sX));
		Edge c;
		int ux,uy,d,newX,newY,checkX,checkY;
		while(!q.isEmpty()){
			c = q.pop();
			ux=c.uX;
			uy=c.uY;
			d=c.d;
			if(dist[layer][uy][ux] != INF) continue;
			dist[layer][uy][ux] = d;
			//north
			checkY = uy-1;
			checkX=ux;
			if(checkY>=2){
				if(board[checkY][checkX]==' '){
					newY=uy-2;
					newX=ux;
					//go north
					q.offer(new Edge(d+1,newY,newX));
				}
			}
			//south
			checkY=uy+1;
			checkX=ux;
			if(checkY<board.length-1){
				if(board[checkY][checkX]==' '){
					newY=uy+2;
					newX=ux;
					//go south
					q.offer(new Edge(d+1,newY,newX));
				}
			}
			//west
			checkY=uy;
			checkX=ux-1;
			if(checkX>=2){
				if(board[checkY][checkX]==' '){
					newY=uy;
					newX=ux-2;
					//go west
					q.offer(new Edge(d+1,newY,newX));
				}
			}
			//east
			checkY=uy;
			checkX=ux+1;
			if(checkX<board[0].length-1){
				if(board[checkY][checkX]==' '){
					newY=uy;
					newX=ux+2;
					//go east
					q.offer(new Edge(d+1,newY,newX));
				}
			}
		}
	}
	
	void readIn() throws IOException{
		BufferedReader reader = new BufferedReader(new FileReader("maze1.in"));
		out = new PrintWriter(new FileWriter("maze1.out"));
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String in;
		st = new StringTokenizer(reader.readLine());
		W=Integer.parseInt(st.nextToken());
		H=Integer.parseInt(st.nextToken());
		board = new char[(2*H)+1][(2*W)+1];
		dist = new int[2][board.length][board[0].length];
		for(int i = 0; i < (2*H)+1; i++){
			for(int j = 0; j < (2*W)+1;j++){
				board[i][j] = (char)reader.read();
			}
			reader.readLine();
		}
		for(int i = 0; i < dist.length; i++){
			for(int j = 0; j < dist[i].length;j++){
				Arrays.fill(dist[i][j], INF);
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
class Edge {
	int d, uX,uY;
	Edge(int D, int uy, int ux){
		d=D;uX=ux;uY=uy;
	}
}