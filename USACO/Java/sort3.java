import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;
/*
ID: eoin.da1
LANG: JAVA
PROG: sort3
 */

class sort3 {
	PrintWriter out;
	int N;
	int[] current;
	int[] sorted;
	int count = 0;
	ArrayList<Integer> inList = new ArrayList<Integer>();
	ArrayList<Integer> sortedList = new ArrayList<Integer>();
	
	public static void main(String[] args) throws IOException{
		sort3 main = new sort3();
		main.run();
	}
	
	public void run() throws IOException{
		readIn();
		compareLists();
		startSwaps();
		printResult();
	}
	
	void startSwaps(){
		for(int i = 0; i < current.length;i++){
			if(current[i] == sorted[i]) continue;
			//search for perfect pair
			for(int j = i; j<current.length;j++){
				if(current[j] == sorted[i] && current[i] == sorted[j]){
					swap(i,j);
					break;
				}
			}
			if(current[i] == sorted[i]) continue;
			for(int j = i; j<current.length;j++){
				if(current[j] == sorted[i]){
					swap(i,j);
					break;
				}
			}
		}
	}
	
	void swap(int i, int j){
		int temp = current[i];
		current[i] = current[j];
		current[j] = temp;
		count++;
	}
	
	private void compareLists() {
		for(int i = 0; i < inList.size(); i++){
			if(inList.get(i) == sortedList.get(i)){
				inList.remove(i);
				sortedList.remove(i);
				i--;
			}
		}
		current = new int[inList.size()];
		sorted = new int[inList.size()];
		for(int i = 0; i < inList.size();i++){
			current[i] = inList.get(i);
			sorted[i] = sortedList.get(i);
		}
	}

	private void readIn() throws IOException {
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader reader = new BufferedReader(new FileReader("sort3.in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter("sort3.out")));
		N = Integer.parseInt(reader.readLine());
		for(int i = 0; i < N; i ++){
			int in = Integer.parseInt(reader.readLine());
			inList.add(in);
		}
		sortedList.addAll(inList);
		Collections.sort(sortedList);
		reader.close();
	}
	
	private void printResult(){
		out.println(count);
		out.close();
	}
}