import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

/*
ID: eoin.da1
LANG: JAVA
TASK: prefix
 */
class Main {
	
	PrintWriter out;
	int N;
	String[] dict;
	ArrayList<Integer>[] adjList;
	int[] visited;
	
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
		StringTokenizer st;
		String in;
		N = Integer.parseInt(reader.readLine());
		reader.readLine();
		for(int i = 0; i < N; i++){
			ArrayList<String> list = new ArrayList<String>();
			while(!(in=reader.readLine()).equals("*")){
				list.add(in);
			}
			dict = new String[list.size()];
			dict = list.toArray(dict);
			visited = new int[dict.length];
			Arrays.sort(dict);
			adjList = new ArrayList[dict.length+1];
			for(int j = 0; j < dict.length; j++){
				adjList[j] = new ArrayList<Integer>();
				adjList[j].clear();
			}
			procList();
			while(true){
				in = reader.readLine();
				if(in == null||in.isEmpty()) break;
				st = new StringTokenizer(in);
				String start = st.nextToken();
				String end = st.nextToken();
				find(start,end);
			}
			if(i!=N-1){
				print("");
			}
		}
	}
	
	void find(String start,String end){
		int s = Arrays.binarySearch(dict, start);
		int e = Arrays.binarySearch(dict, end);
		visited = new int[visited.length];
		Arrays.fill(visited, -1);
		LinkedList<Integer> q = new LinkedList<Integer>();
		q.add(s);
		visited[s] = 0;
		while(!q.isEmpty()){
			int c = q.removeFirst();
			if(c==e){
				print(dict[s] + " " + dict[e] + " " + visited[c]);
				return;
			}
			for(int i = 0; i < adjList[c].size();i++){
				int pos = adjList[c].get(i);
				if(visited[pos]!=-1) continue;
				visited[pos] = visited[c]+1;
				q.add(pos);
			}
		}
	}
	
	void procList(){
		for(int i = 0; i < dict.length; i++){
			for(int j = 0; j < dict.length; j++){
				if(i==j) continue;
				if(dict[i].length()!=dict[j].length()) continue;
				if(difByOne(dict[i],dict[j])){
					adjList[i].add(j);
				}
			}
		}
	}
	
	boolean difByOne(String in1, String in2){
		int count = 0;
		for(int i = 0; i < in1.length(); i++){
			if(in1.charAt(i) != in2.charAt(i)) count++;
		}
		if(count == 1) return true;
		return false;
	}
	
	private void print(String s){
		System.out.println(s);
	}
	
	void stop(){
		
	}
}