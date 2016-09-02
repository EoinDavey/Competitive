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
TASK: humble
 */
class humble {
	
	PrintWriter out;
	
	int K,N;
	int[] primes;
	int[] memo;
	ArrayList<Integer> h = new ArrayList<Integer>();
	
	public static void main(String[] args) throws IOException{
		humble main = new humble();
		main.run();
	}
	
	public void run() throws IOException{
		readIn();
		proc();
		stop();
	}
	
	void proc(){
		int pos=0;
		while(pos<=N){
			int next=Integer.MAX_VALUE;
			int c = 0;
			ArrayList<Integer> which = new ArrayList<Integer>();
			for(int i = 0; i < K; i++){
				c=primes[i] * h.get(memo[i]);
				if(c<next){
					next = c;
					which = new ArrayList<Integer>();
					which.add(i);
				}
				else if(c==next){
					which.add(i);
				}
			}
			for(int i = 0; i < which.size(); i++) memo[which.get(i)]++;
			h.add(next);
			pos++;
		}
		print(""+h.get(N));
	}

	private void readIn() throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader("humble.in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter("humble.out")));
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String in;
		st=new StringTokenizer(reader.readLine());
		K=Integer.parseInt(st.nextToken());
		N=Integer.parseInt(st.nextToken());
		primes = new int[K];
		memo = new int[K];
		st = new StringTokenizer(reader.readLine());
		for(int i = 0; i < K; i++){
			primes[i] = Integer.parseInt(st.nextToken());
		}
		h.add(1);
	}
	
	
	private void print(String s){
		out.println(s);
	}
	
	void stop(){
		out.close();
	}
}
