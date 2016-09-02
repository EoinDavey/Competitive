import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


class Main {
	
	int N,P;
	String state = "+x";
	String[] bends;
	public static void main(String[] args) throws IOException{
		Main main = new Main();
		main.run();
	}
	
	public void run() throws IOException{
		readIn();
	}
	
	void process(){
		String bend;
		for(int i = 0; i < bends.length; i++){
			bend = bends[i];
			if(bend.equals("No"))continue;
			if(state.equals("+x")) state = bend;
			else if(state.equals("+z")){
				if(bend.equals("+z")) state = "-x";
				else if(bend.equals("-z")) state = "+x";
			}else if(state.equals("-z")){
				if(bend.equals("-z")) state = "-x";
				else if(bend.equals("+z")) state = "+x";
			}else if(state.equals("+y")){
				if(bend.equals("+y")) state = "-x";
				else if(bend.equals("-y")) state = "+x";
			}else if(state.equals("-y")){
				if(bend.equals("-y")) state = "-x";
				else if(bend.equals("+y")) state = "+x";
			}else if(state.equals("-x")){
				char[] bendChar = bend.toCharArray();
				if(bendChar[0] == '+') bendChar[0]='-';
				else if(bendChar[0] == '-') bendChar[0]='+';
				state = new String(bendChar);
			}
		}
		print(state);
	}

	private void readIn() throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String in;
		while(true){
			in = reader.readLine();
			if(in.equals("0")) break;
			N = Integer.parseInt(in);
			bends = new String[N-1];
			state = "+x";
			st = new StringTokenizer(reader.readLine());
			for(int i = 0; i < N-1;i++){
				bends[i] = st.nextToken();
			}
			process();
		}
		reader.close();
	}
	
	private void print(String s){
		System.out.println(s);
	}
}