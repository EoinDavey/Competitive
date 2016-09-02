import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Scanner;
/*
ID: eoin.da1
LANG: JAVA
PROG: wormhole
 */

class wormhole {
	int N;
	long[] X;
	long[] Y;
	int[] paired;
	int[] next_on_right;
	PrintWriter out;
	int totalOut = 0;
	public static void main(String[] args) throws IOException{
		wormhole main = new wormhole();
		main.run();
	}
	
	public void run() throws IOException{
		readIn();
		generateNextOnRight();
		generatePairs();
		print();
	}
	
	private void generateNextOnRight() {
		next_on_right = new int[N+1];
		for(int i = 1; i < N+1; i++){
			for(int j = 1; j<N+1; j++){
				//On the right
				if(Y[i] == Y[j] && X[j] < X[i]){
					//check if closer
					if(next_on_right[i] == 0 || (X[j] - X[i]) > (X[next_on_right[i]] - X[i])){
						next_on_right[i] = j;
					}
				}
			}
		}
	}

	void print(){
		out.println(totalOut);
		out.close();
	}
	
	void generatePairs(){
		//find first unpaired
		int pair = 0;
		int total = 0;
		for(int i = 1; i<=N; i++){
			if(paired[i] == 0){
				pair = i;
				break;
			}
		}
		//All Paired
		if(pair == 0){
			//printPairs();
			if(testForCycle()){
				totalOut++;
			}
			return;
		}
		//pair with each
		for(int i = pair+1; i <=N;i++){
			if(paired[i] == 0){
				paired[pair] = i;
				paired[i] = pair;
				generatePairs();
				paired[pair] = paired[i] = 0;
			}
		}
		return;
	}
	
	boolean testForCycle(){
		/*
		 * for each wormhole, take wormhole on right
		 */
		int pos;
		for(int i = 1; i <= N; i++){
			pos = i;
			for(int j = 0; j<N;j++){
				pos = next_on_right[paired[pos]];
			}
			if(pos != 0){
				return true;
			}
		}
		return false;
	}
	
	void printPairs(){
		for(int i = 1; i <= N; i++){
			System.out.print(i + "-" + paired[i] + ", ");
		}
		System.out.println();
	}
	
	void readIn() throws IOException{
		//Scanner scanner = new Scanner(System.in);
		Scanner scanner = new Scanner(new FileReader("wormhole.in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter("wormhole.out")));
		N = scanner.nextInt();
		X = new long[N+1];
		Y = new long[N+1];
		paired = new int[N+1];
		for(int i = 1; i <= N; i++){
			X[i] = scanner.nextLong();
			Y[i] = scanner.nextLong();
		}
		scanner.close();
	}
}