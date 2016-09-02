import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


class Main {
	
	int N,P;
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
		int reqs,count;
		String in,name,bestProp;
		float bestPrice,price,comp,bestComp;
		count = 1;
		while(true){
			bestPrice = Float.MAX_VALUE;
			bestComp = 0;
			bestProp="";
			in = reader.readLine();
			if(in.equals("0 0")) break;
			st = new StringTokenizer(in);
			N=Integer.parseInt(st.nextToken());
			P=Integer.parseInt(st.nextToken());
			for(int i = 0; i < N; i++){
				reader.readLine();
			}
			for(int i = 0; i < P; i++){
				name = reader.readLine();
				st = new StringTokenizer(reader.readLine());
				price = Float.parseFloat(st.nextToken());
				reqs = Integer.parseInt(st.nextToken());
				for(int j = 0; j < reqs;j++){
					reader.readLine();
				}
				comp = reqs/(float)N;
				if(comp>bestComp){
					bestProp = name;
					bestComp = comp;
					bestPrice = price;
				} else if(comp==bestComp&&price<bestPrice){
					bestProp = name;
					bestComp = comp;
					bestPrice = price;
				}
			}
			if(count>1)print("");
			print("RFP #" + count);
			print(bestProp);
			count++;
		}
		reader.close();
	}
	
	private void print(String s){
		System.out.println(s);
	}
}