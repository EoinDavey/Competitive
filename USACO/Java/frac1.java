import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
/*
ID: eoin.da1
LANG: JAVA
PROG: frac1
 */

class frac1 {
	PrintWriter out;
	int N;
	ArrayList<Fraction> fractions = new ArrayList<Fraction>();
	
	public static void main(String[] args) throws IOException{
		frac1 main = new frac1();
		main.run();
	}
	
	public void run() throws IOException{
		readIn();
		genFractions();
		sortFractions();
		printResult();
	}
	
	private void sortFractions() {
		Collections.sort(fractions);
	}

	private void genFractions() {
		//i is bottom, j is top
		if(N==0) return;
		fractions.add(new Fraction(0,1));
		fractions.add(new Fraction(1,1));
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <=i-1; j++){
				if(isReducible(i,j)) continue;
				fractions.add(new Fraction(j,i));
			}
		}
	}

	private boolean isReducible(int top, int bottom) {
		if(bottom%top== 0){
			if(top == 1) return false;
			else return true;
		}
		if(gcd(top,bottom) != 1){
			return true;
		}
		return false;
	}

	int gcd(int k, int m){
		while(k!=m){
			if(k > m){
				k = k-m;
			} else {
				m=m-k;
			}
		}
		return k;
	}

	private void readIn() throws IOException {
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader reader = new BufferedReader(new FileReader("frac1.in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter("frac1.out")));
		N = Integer.parseInt(reader.readLine());
		reader.close();
	}
	
	private void printResult(){
		for(int i = 0; i < fractions.size(); i++){
			Fraction f = fractions.get(i);
			out.println(f.top + "/" + f.bottom);
		}
		out.close();
	}
}
class Fraction implements Comparable<Fraction>{
	int top;
	int bottom;
	
	Fraction(int t, int b){
		this.top = t;
		this.bottom = b;
	}
	
	@Override
	public int compareTo(Fraction o) {
		if(this.top*o.bottom > this.bottom * o.top){
			return 1;
		}
		return -1;
	}
}