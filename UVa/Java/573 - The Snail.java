import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


class Main {
	
	double height,climbHeight,slideDistance,fatigue;
	public static void main(String[] args) throws IOException{
		Main main = new Main();
		main.run();
	}
	
	public void run() throws IOException{
		readIn();
	}
	

	private void readIn() throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String in;
		while(true){
			in = reader.readLine();
			if(in==null||in.isEmpty()) break;
			st = new StringTokenizer(in);
			height=Double.parseDouble(st.nextToken());
			climbHeight=Double.parseDouble(st.nextToken());
			slideDistance=Double.parseDouble(st.nextToken());
			fatigue=(Double.parseDouble(st.nextToken()) /100) * climbHeight;
			if(height==0) break;
			process();
		}
		reader.close();
	}
	
	void process(){
		int count = 1;
		double climb = 0;
		climbHeight+= fatigue;
		while(true){
			//climb
			climbHeight -= fatigue;
			if(climbHeight < 0) climbHeight = 0;
			climb += climbHeight;
			if(climb > height){
				print("success on day " + count);
				break;
			}
			//slip
			climb -= slideDistance;
			if(climb<0){
				print("failure on day " + count);
				break;
			}
			count++;
		}
	}

	private void print(String s){
		System.out.println(s);
	}
}