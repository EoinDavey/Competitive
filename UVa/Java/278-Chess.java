import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


class Main {
	
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
		int count = 0;
		int no = Integer.parseInt(reader.readLine());
		while(count<no){
			in = reader.readLine();
			if(in==null||in.isEmpty())continue;
			st = new StringTokenizer(in);
			String piece = st.nextToken();
			if(piece==null||piece.equals("")) continue;
			int m =Integer.parseInt(st.nextToken());
			int n =Integer.parseInt(st.nextToken());
			int result = 0;
			switch(piece.charAt(0)){
			case 'r':
				result = Math.min(m, n); break;
			case 'k':
				if(m%2==0){
					result = (m/2) *n;
				} else if(n%2==0){
					result = (n/2) * m;
				} else {
					int max = Math.max(m, n);
					int min = Math.min(m, n);
					int halfMax = ((max)+1)/2;
					int group = (2*halfMax) - 1;
					int halfMin = ((min+1)/2);
					result = group*halfMin - (halfMax-1);
				}
				break;
			case 'Q':
				result = Math.min(m, n);
				break;
			case 'K':
				if(m%2!=0&&n%2!=0){
					result = ((m+1)/2) * ((n+1)/2);
				} else if(m%2==0&&n%2==0){
					result = (m/2) * (n/2);
				} else if(m%2==0){
					result = (m/2) * ((n+1)/2);
				} else {
					result = ((m+1)/2) * (n/2);
				}
				break;
			}
			print("" + result);
			count++;
		}
	}
	
	private void print(String s){
		System.out.println(s);
	}
}