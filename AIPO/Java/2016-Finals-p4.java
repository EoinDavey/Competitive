import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;


public class p4 {
	
	final int INF = (int) Math.pow(10,9);
	
	int N;
	int[] list;

	public static void main(String[] args) throws IOException {
		p4 main = new p4();
		main.run();
	}
	
	void run() throws IOException{
		readIn();
		proc();
		stop();
	}
	
	void proc(){
		int pos,prev,sum,length,max,maxSum;
		pos=prev=sum=length=max=maxSum=0;
		while(pos<N){
			if(list[pos]>=prev){
				sum+=list[pos];
				prev = list[pos];
				length++;
			} else {
				if(length>max){
					max = length;
					maxSum = sum;
				}
				sum=list[pos];
				length=1;
				prev = list[pos];
			}
			pos++;
		}
		//second check in case max sequence runs until end
		if(length>max){
			max = length;
			maxSum = sum;
			sum=0;
			length=0;
		}
		print("" + max + " " + maxSum);
	}
	
	void readIn() throws IOException{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String in;
		
		N=Integer.parseInt(reader.readLine());
		st=new StringTokenizer(reader.readLine());
		list = new int[N];
		for(int i = 0; i < N; i++){
			list[i] = Integer.parseInt(st.nextToken());
		}
		
		reader.close();
	}
	
	void stop(){
		
	}
	
	double toRadians(double deg){
		return deg*(Math.PI/180);
	}
	
	void print(String s){
		System.out.println(s);
	}

}

