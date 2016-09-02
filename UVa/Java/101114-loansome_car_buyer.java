import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	PrintWriter out;
	public static void main(String[] args) throws IOException{
		Main main = new Main();
		main.run();
	}
	
	public void run()throws IOException{
		readIn();
	}
	
	void readIn() throws IOException{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		while(true){
			st = new StringTokenizer(reader.readLine());
			int length = Integer.parseInt(st.nextToken());
			if(length<0) break;
			if(length==0){
				print("0 months");
				break;
			}
			float down = Float.parseFloat(st.nextToken());
			float amount = Float.parseFloat(st.nextToken())+down;
			float loanVal = amount-down;
			float monthly = loanVal/length;
			loanVal+=monthly;
			int n = Integer.parseInt(st.nextToken());
			float[] dep = new float[length+1];
			for(int i = 0; i < n; i++){
				st = new StringTokenizer(reader.readLine());
				dep[Integer.parseInt(st.nextToken())] = Float.parseFloat(st.nextToken());
			}
			float currentDep = 0;
			for(int i = 0; i <= length; i++){
				loanVal -=monthly;
				if(dep[i]!=0) currentDep = dep[i];
				amount = amount*((float)1-currentDep);
				if(loanVal < amount){
					if(i==1){
						print("1 month");
						break;
					}
					print((i) + " months");
					break;
				}
			}
		}
	}
	
	void print(String s){ 
		System.out.println(s);
	}
}
