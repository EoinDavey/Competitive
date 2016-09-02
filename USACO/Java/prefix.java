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
TASK: prefix
 */
class prefix {
	
	String[] primitives = {};
	String S="";
	boolean[] visited;
	PrintWriter out;
	
	public static void main(String[] args) throws IOException{
		prefix main = new prefix();
		main.run();
	}
	
	public void run() throws IOException{
		readIn();
		process();
		stop();
	}
	
	private void process() {
		
		int max = 0;
		visited[0] = true;
		for(int i = 0; i < visited.length;i++){
			if(visited[i]){
				for(int j = 0; j < primitives.length; j++){
					int stepUp = i+primitives[j].length();
					if(stepUp>S.length()) continue;
					String su = S.substring(i, stepUp);
					if(su.equals(primitives[j])){
						if(stepUp>max)max=stepUp;
						visited[stepUp] = true;
					}
				}
			}
		}
		out.println(max);
		out.close();
	}

	void stop(){
		
	}
	
	private void readIn() throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader("prefix.in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter("prefix.out")));
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String in;
		StringBuilder sb = new StringBuilder();
		ArrayList<String> primitiveList = new ArrayList<String>();
		while(!(in = reader.readLine()).equals(".")){
			st=new StringTokenizer(in);
			while(st.hasMoreTokens()){
				primitiveList.add(st.nextToken());
			}
			primitives = primitiveList.toArray(primitives);
		}
		while(true){
			in=reader.readLine();
			if(in==null||in.isEmpty()){
				break;
			}
			sb.append(in);
		}
		S=sb.toString();
		visited=new boolean[S.length()+1];
	}
	
	private void print(String s){
		System.out.println(s);
	}
}