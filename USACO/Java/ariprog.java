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
PROG: ariprog
 */

class ariprog {
	PrintWriter out;
	int N, M, totalOut;
	int[] biSquares;
	boolean numbers[];
	boolean checked[];
	public static void main(String[] args) throws IOException{
		ariprog main = new ariprog();
		main.run();
	}
	public void run() throws IOException{
		readIn();
		generateBiSquares();
		generateSequences();
		//print();
		out.close();
	}
	
	private void generateSequences() {
		boolean valid = false;
		boolean printed = false;
		int a;
		for(int b = 1; b < (biSquares[biSquares.length-1]/(N-1)) + 1; b++){
			//checked = new boolean[biSquares.length];
			for(int aInd = 0; aInd < biSquares.length;aInd++){
				valid = true;
				//if(checked[aInd]){
				//	continue;
				//}
				a = biSquares[aInd];
				//Start at each element
				for(int j = 0; j < N; j++){
					//Step N times;
					if(a+b*j >= numbers.length){
						valid = false;
						break;
					}
					if(!numbers[a+b*j]){
						valid = false;
						break;
					} else {
						//checked[n] = true;
					}
				}
				if(valid){
					//Sequence exists
					printed = true;
					out.println("" + a + " " + b);
				}
			}
		}
		if(!printed){
			out.println("NONE");
		}
	}
	private void generateBiSquares() {
		ArrayList<Integer> list = new ArrayList<Integer>();
		for(int i = 0; i <= M; i++){
			for(int j = i; j<=M;j++){
				if(!list.contains((i*i) + (j*j))){
					list.add((i*i) + (j*j));
				}
			}
		}
		biSquares = new int[list.size()];
		checked= new boolean[list.size()];
		for(int i = 0; i < list.size(); i++){
			biSquares[i] = list.get(i);
		}
		Arrays.sort(biSquares);
		numbers = new boolean[biSquares[biSquares.length-1] + 1];
		for(int i = 0; i < biSquares.length; i++){
			numbers[biSquares[i]] = true;
		}
	}
	void readIn() throws IOException{
		//Scanner scanner = new Scanner(System.in);
		Scanner scanner = new Scanner(new FileReader("ariprog.in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter("ariprog.out")));
		N = scanner.nextInt();
		M = scanner.nextInt();
		scanner.close();
	}
	void print(){
		for(int i = 0; i < biSquares.length; i++){
			out.println(biSquares[i]);
		}
		out.println(totalOut);
		//out.close();
	}
}