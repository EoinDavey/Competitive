import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Scanner;
/*
ID: eoin.da1
LANG: JAVA
PROG: milk3
 */

class milk3 {
	PrintWriter out;
	int[] cups = new int[3];
	final int A = 0;
	final int B = 1;
	final int C = 2;
	int[] size = new int[3];
	ArrayList<Integer> results = new ArrayList<Integer>();
	boolean[][][] checked = new boolean[21][21][21];
	public static void main(String[] args) throws IOException{
		milk3 main = new milk3();
		main.run();
	}
	
	public void run() throws IOException{
		readIn();
		solve();
		printResult();
	}
	
	void solve(){
		//mark as checked
		mark();
		//check if A is empty
		if(cups[A] == 0){
			results.add(cups[C]);
		}
		//pour from A
		if(cups[A] > 0){
			//to B
			if(cups[B] < size[B]){
				int change = Math.min(cups[A], size[B] - cups[B]);
				cups[A] = cups[A] - change;
				cups[B] = cups[B] + change;
				if(!isChecked()){
					solve();
				}
				cups[A] = cups[A] + change;
				cups[B] = cups[B] - change;
			}
			//To C
			if(cups[C] < size[C]){
				int change = Math.min(cups[A], size[C] - cups[C]);
				cups[A] = cups[A] - change;
				cups[C] = cups[C] + change;
				if(!isChecked()){
					solve();
				}
				cups[A] = cups[A] + change;
				cups[C] = cups[C] - change;
			}
		}
		//pour from B
		if(cups[B] > 0){
			//to C
			if(cups[C] < size[C]){
				int change = Math.min(cups[B], size[C] - cups[C]);
				cups[B] = cups[B] - change;
				cups[C] = cups[C] + change;
				if(!isChecked()){
					solve();
				}
				cups[B] = cups[B] + change;
				cups[C] = cups[C] - change;
			}
			//To A
			if(cups[A] < size[A]){
				int change = Math.min(cups[B], size[A] - cups[A]);
				cups[B] = cups[B] - change;
				cups[A] = cups[A] + change;
				if(!isChecked()){
					solve();
				}
				cups[B] = cups[B] + change;
				cups[A] = cups[A] - change;
			}
		}
		//pour from C
		if(cups[C] > 0){
			//to A
			if(cups[A] < size[A]){
				int change = Math.min(cups[C], size[A] - cups[A]);
				cups[C] = cups[C] - change;
				cups[A] = cups[A] + change;
				if(!isChecked()){
					solve();
				}
				cups[C] = cups[C] + change;
				cups[A] = cups[A] - change;
			}
			//To B
			if(cups[B] < size[B]){
				int change = Math.min(cups[C], size[B] - cups[B]);
				cups[C] = cups[C] - change;
				cups[B] = cups[B] + change;
				if(!isChecked()){
					solve();
				}
				cups[C] = cups[C] + change;
				cups[B] = cups[B] - change;
			}
		}
	}
	
	boolean isChecked(){
		return checked[cups[A]][cups[B]][cups[C]];
	}
	
	void mark(){
		checked[cups[A]][cups[B]][cups[C]] = true;
	}
	
	void printCups(){
		for(int i = A; i <= C; i++){
			System.out.print("|" + cups[i] + "|");
		}
		System.out.println();
	}
	private void readIn() throws IOException{
		//Scanner scanner = new Scanner(System.in);
		Scanner scanner = new Scanner(new FileReader("milk3.in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter("milk3.out")));
		size[A] = scanner.nextInt();
		size[B] = scanner.nextInt();
		size[C] = scanner.nextInt();
		cups[C] = size[C];
		scanner.close();
	}
	
	private void printResult() {
		Collections.sort(results);
		for(int i = 0; i<results.size() - 1; i++){
			out.print(results.get(i) + " ");
		}
		out.println(results.get(results.size()-1));
		out.close();
	}
}