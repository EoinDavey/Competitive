import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
/*
ID: eoin.da1
LANG: JAVA
PROG: milk
 */

class milk {
	public static void main(String[] args) throws IOException{
		//Scanner scanner = new Scanner(System.in);
		Scanner scanner = new Scanner(new FileReader("milk.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("milk.out")));
		int N = scanner.nextInt();
		int M = scanner.nextInt();
		Farmer[] farmers = new Farmer[M];
		for(int i = 0; i < M; i++){
			farmers[i] = new Farmer(scanner.nextInt(), scanner.nextInt());
		}
		Arrays.sort(farmers);
		int cost = 0;
		int required = N;
		Farmer f;
		for(int i = 0; i< M; i++){
			f = farmers[i];
			if(f.amount < required){
				cost += f.price * f.amount;
				required -= f.amount;
				f.amount = 0;
			} else {
				cost += f.price * required;
				required = 0;
			}
		}
		out.println(cost);
		out.close();
	}
}

class Farmer implements Comparable<Farmer>{
	int price;
	int amount;
	
	Farmer(int price, int amount){
		this.price = price;
		this.amount = amount;
	}

	@Override
	public int compareTo(Farmer f) {
		return Integer.valueOf(this.price).compareTo(f.price);
	}
}