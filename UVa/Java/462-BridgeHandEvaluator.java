import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.StringTokenizer;


class Main {
	
	PrintWriter out = new PrintWriter(System.out);
	boolean[][] hand;
	int[] count;
	int maxCount;
	public static void main(String[] args) throws IOException{
		Main main = new Main();
		main.run();
	}
	
	public void run() throws IOException{
		readIn();
	}
	
	private void readIn() throws IOException {
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		Scanner sc = new Scanner(System.in);
		StringTokenizer st;
		String in;
		while(sc.hasNextLine()){
			in = sc.nextLine();
			if(in==null) break;
			if(in.equals(""))continue;
			hand = new boolean[4][14];
			count=new int[4];
			maxCount = 0;
			st = new StringTokenizer(in);
			for(int i = 0; i < 13; i++){
				place(st.nextToken().toCharArray());
			}
			process();
		}
		out.close();
	}
	
	private void process() {
		int total = 0;
		//rule 1
		for(int i = 0; i < 4; i++){
			if(hand[i][0])total+=4;
			if(hand[i][12])total+=3;
			if(hand[i][11])total+=2;
			if(hand[i][10])total++;
		}
		
		//count
		for(int i = 0; i<4; i++){
			int sub = 0;
			for(int j = 0; j < 13; j++){
				if(hand[i][j])sub++;
			}
			count[i] = sub;
			if(sub>maxCount) maxCount = sub;
		}
		
		//rule 2,3,4 and stopcheck
		for(int i = 0; i< 4; i++){
			if(hand[i][12]){
				if(count[i]<2)total--;
				else hand[i][13]=true;
			}
			if(hand[i][11]){
				if(count[i]<3)total--;
				else hand[i][13]=true;
			}
			if(hand[i][10]){
				if(count[i]<4)total--;
			}
			if(hand[i][0])hand[i][13]=true;
		}
		//check for stopped
		boolean noTrump = true;;
		if(total>=16){
			for(int i = 0; i < 4; i++){
				if(!hand[i][13]){
					noTrump = false;
					break;
				}
			}
		} else noTrump=false;
		if(noTrump){
			print("BID NO-TRUMP");
			return;
		}
		//rule 5,6,7
		for(int i = 0; i < 4; i++){
			if(count[i]==2)total++;
			if(count[i]<=1)total+=2;
		}
		if(total<14){
			print("PASS");
			return;
		}
		for(int i = 0; i<4; i++){
			if(count[i] == maxCount){
				switch(i){
				case 0:
					print("BID S"); return;
				case 1:
					print("BID H"); return;
				case 2:
					print("BID D"); return;
				case 3:
					print("BID C"); return;
				}
			}
		}
	}

	void place(char[] in){
		int suit,val;
		suit=val=0;
		
		switch(in[1]){
		case 'S':
			break;
		case 'H':
			suit = 1;
			break;
		case 'D':
			suit = 2;
			break;
		case 'C':
			suit = 3;
			break;
		}
		
		switch(in[0]){
			case 'A':
				break;
			case '2':
				val=1;
				break;
			case '3':
				val = 2;
				break;
			case '4':
				val=3;
				break;
			case '5':
				val=4;
				break;
			case '6':
				val=5;
				break;
			case '7':
				val=6;
				break;
			case '8':
				val=7;
				break;
			case '9':
				val=8;
				break;
			case 'T':
				val=9;
				break;
			case 'J':
				val=10;
				break;
			case 'Q':
				val=11;
				break;
			case 'K':
				val=12;
				break;
		}
		
		hand[suit][val] = true;
	}
	
	private void print(String s){
		out.println(s);
	}
}