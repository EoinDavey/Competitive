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
PROG: skidesign
 */

class skidesign {
	PrintWriter out;
	int N, max, min;
	float mean;
	int[] elevations;
	ArrayList<Integer> list;
	int totalOut = Integer.MAX_VALUE;
	public static void main(String[] args) throws IOException{
		skidesign main = new skidesign();
		main.run();
	}
	public void run() throws IOException{
		readIn();
		reduce();
		print();
	}
	
	void reduce(){
		int upLim, lowLim;
		upLim=lowLim= 0;
		for(lowLim = 0; lowLim <= max-17; lowLim++){
			upLim = 17+lowLim;
			list.add(calcTotal(lowLim, upLim));
		}
	}
	
	int calcTotal(int lowLim, int upLim){
		int in,total,change;
		in=total = 0;
		for(int i = 0; i < N; i++){
			in = elevations[i];
			if(in < lowLim){
				//increase
				change = lowLim - in;
				total += change*change;
			} else if (in > upLim){
				//decrease
				change = upLim - in;
				total += change*change;
			}
		}
		return total;
	}

	void readIn() throws IOException{
		//Scanner scanner = new Scanner(System.in);
		Scanner scanner = new Scanner(new FileReader("skidesign.in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter("skidesign.out")));
		N = scanner.nextInt();
		elevations = new int[N];
		list = new ArrayList<Integer>();
		max = 0;
		min = Integer.MAX_VALUE;
		int in;
		for(int i = 0; i < N; i++){
			in = scanner.nextInt();
			if(in > max) max = in;
			if(in < min) min = in;
			elevations[i] = in;
		}
		//Arrays.sort(elevations);
		scanner.close();
	}
	void print(){
		for(int i = 0; i < list.size(); i++){
			if(list.get(i) < totalOut) totalOut= list.get(i);
		}
		out.println(totalOut);
		out.close();
	}
}