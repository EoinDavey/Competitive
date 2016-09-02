import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.StringTokenizer;

/*
ID: eoin.da1
LANG: JAVA
TASK: cowtour
*/

public class cowtour {
	
	PrintWriter out;
	
	int N;
	boolean[][] adjMat;
	int[][] locs;
	double[][] distIn;
	double[][]dist;
	int[] sets;
	double[] diameters;
	double[] furthest;
	
	final int INF = (int) Math.pow(10, 9);
	
	public static void main(String[] args) throws IOException{
		cowtour main = new cowtour();
		main.run();
	}
	
	public void run()throws IOException{
		readIn();
		process();
		stop();
	}
	
	void process(){
		apsp();
		fillDiameters();
		double min = Integer.MAX_VALUE;
		for(int i = 0; i < N; i++){
			for(int j = i+1; j < N; j++){
				if(dist[i][j]>=INF){
					double newD = furthest[i] + euc(i,j) + furthest[j];
					newD = Math.max(newD, Math.max(diameters[sets[i]], diameters[sets[j]]));
					if(newD<min) min=newD;
				}
			}
		}
		print(min);
	}
	
	void fillDiameters(){
		int setNo = findSet();
		furthest = new double[N];
		diameters = new double[setNo];
		for(int i = 0; i < setNo; i++){
			double fMax=0;
			for(int j = 0; j < N; j++){
				double vMax=0;
				if(sets[j]!=i)continue;
				for(int k = 0; k<N;k++){
					if(k==j) continue;
					if(dist[j][k] > vMax&&dist[j][k]<INF) vMax = dist[j][k];
				}
				furthest[j] = vMax;
				if(vMax>fMax)fMax=vMax;
			}
			diameters[i] = fMax;
		}
	}
	
	int findSet(){
		sets = new int[N];
		Arrays.fill(sets, -1);
		int set = 0;
		for(int i = 0; i < N;i++){
			if(sets[i]==-1){
				sets[i]=set;
				fillFrom(i,set);
				set++;
			}
		}
		return set;
	}
	
	void fillFrom(int i,int set){
		for(int j = 0; j < N;j++){
			if(adjMat[i][j]&&sets[j]==-1){
				sets[j] = set;
				fillFrom(j,set);
			}
		}
	}
	
	void apsp(){
		for(int k = 0; k<N;k++){
			for(int i = 0; i<N;i++){
				for(int j = 0; j<N;j++){
					dist[i][j] = Math.min(dist[i][j], dist[i][k]+dist[k][j]);
				}
			}
		}
	}
	
	double euc(int i, int j){
		int dx,dy;
		dx = locs[i][0]-locs[j][0];
		dy = locs[i][1]-locs[j][1];
		return Math.sqrt(dx*dx+dy*dy);
	}
	
	void readIn() throws IOException{
		BufferedReader reader = new BufferedReader(new FileReader("cowtour.in"));
		out = new PrintWriter(new FileWriter("cowtour.out"));
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String in;
		N = Integer.parseInt(reader.readLine());
		locs = new int[N][2];
		adjMat = new boolean[N][N];
		distIn = new double[N][N];
		dist = new double[N][N];
		double d;
		for(int i = 0; i < N; i++){
			st = new StringTokenizer(reader.readLine());
			locs[i] = new int[]{Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken())};
		}
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				char c = (char) reader.read();
				if(c=='1'){
					adjMat[i][j]=adjMat[j][i]=true;
					d = euc(i,j);
					distIn[i][j]=distIn[j][i]=dist[i][j]=dist[j][i] = d;
				} else {
					adjMat[i][j]=adjMat[j][i]=false;
					distIn[i][j]=distIn[j][i]=dist[i][j]=dist[j][i]=INF;
				}
			}
			reader.readLine();
		}
	}
	
	void stop(){
		out.close();
	}
	
	void print(double d){
		String s=String.format("%.6f", d);
		while(s.length()-s.indexOf('.')<6){
			s = s+'0';
		}
		out.println(s);
	}
}