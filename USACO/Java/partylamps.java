import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Arrays;
import java.util.StringTokenizer;

/*
ID: eoin.da1
LANG: JAVA
TASK: lamps
*/

public class lamps {
	
	int N,C;
	int state = 0000;
	boolean[] onList;
	boolean[] offList;
	boolean[] currentState;
	PrintWriter out;
	ArrayList<BigInteger> results = new ArrayList<BigInteger>();
	public static void main(String[] args) throws IOException{
		lamps main = new lamps();
		main.run();
	}
	
	public void run()throws IOException{
		readIn();
		backtrack(-1);
		printResults();
	}
	
	void printResults(){
		String res = "";
		if(results.size()==0){
			out.println("IMPOSSIBLE");
			out.close();
			return;
		}
		Collections.sort(results);
		for(int i = 0; i < results.size(); i++){
			res=results.get(i).toString(2);
			while(res.length()<N){
				res = "0" + res;
			}
			out.println(res);
		}
		out.close();
	}
	
	private void backtrack(int depth) {
		for(int i = depth+1; i < 4;i++){
			if((state&(1<<i))!=(1<<i)){
				state = (state|(1<<i));
				backtrack(i);
				state = (state&(~(1<<i)));
			}
		}
		check();
	}

	private void check() {
		currentState = new boolean[N+1];
		Arrays.fill(currentState, true);
		int c = 0;
		for(int i = 0; i < 4;i++){
			if((state&(1<<i))==(1<<i)){
				c++;
			}
		}
		if(c==0||C==0){
			if(C==0&&c==0){
				process();
				return;
			} else if(C>0){
				if(C%2==0){
					process();
					return;
				}
			}
		}else if(C%c==2||C%c==0){
			process();
		}
	}
	
	void process(){
		for(int i = 0; i < 4; i++){
			if((state&(1<<i))==(1<<i)){
				switch(i){
				case 0:
					for(int j = 1; j <=N;j++){
						currentState[j] = !currentState[j];
					}
					break;
				case 1:
					for(int j = 1; j <=N;j+=2){
						currentState[j] = !currentState[j];
					}
					break;
				case 2:
					for(int j = 2; j <=N;j+=2){
						currentState[j] = !currentState[j];
					}
					break;
				case 3:
					for(int j = 1; j <=N;j+=3){
						currentState[j] = !currentState[j];
					}
					break;
				}
			}
		}
		for(int i = 1; i < onList.length;i++){
			if(onList[i]==true && currentState[i]==false) return;
		}
		for(int i = 1; i < offList.length;i++){
			if(offList[i]==true && currentState[i]==true) return;
		}
		StringBuilder sb = new StringBuilder();
		for(int i = 1; i < currentState.length;i++){
			if(currentState[i]){
				sb.append("1");
			} else sb.append("0");
		}
		BigInteger b = new BigInteger(sb.toString(),2);
		if(!results.contains(b)) results.add(b);
	}

	void readIn() throws IOException{
		BufferedReader reader = new BufferedReader(new FileReader("lamps.in"));
		out = new PrintWriter(new FileWriter("lamps.out"));
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String in;
		N=Integer.parseInt(reader.readLine());
		C=Integer.parseInt(reader.readLine());
		onList = new boolean[N+1];
		offList = new boolean[N+1];
		currentState = new boolean[N+1];
		Arrays.fill(currentState, true);
		st=new StringTokenizer(reader.readLine());
		while(!(in=st.nextToken()).equals("-1")){
			onList[Integer.parseInt(in)] = true;
		}
		st=new StringTokenizer(reader.readLine());
		while(!(in=st.nextToken()).equals("-1")){
			offList[Integer.parseInt(in)] = true;
		}
	}
	
	void print(String s){ 
		out.println(s);
	}
}
