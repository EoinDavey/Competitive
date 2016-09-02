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
PROG: combo
 */

class combo {
	static int N;
	static int[] input;
	static int[] master;
	public static void main(String[] args) throws IOException{
		//Scanner scanner = new Scanner(System.in);
		Scanner scanner = new Scanner(new FileReader("combo.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("combo.out")));
		N = scanner.nextInt();
		input = new int[3];
		master = new int[3];
		for(int i = 0;i<3;i++){
			input[i] = scanner.nextInt();
		}
		for(int i = 0;i<3;i++){
			master[i] = scanner.nextInt();
		}
		int i,j,k,gapI,gapJ,gapK,count;
		count = 0;
		for(i = 1; i <= N; i++){
			gapI = gap(i, 0);
				if(gapI > 2){
					continue;
				}
			for(j = 1; j<= N; j++){
				gapJ = gap(j, 1);
				if(gapJ > 2){
					continue;
				}
				for(k = 1; k <= N; k++){
					gapK = gap(k,2);
					if(gapK <= 2){
						//checkInput
						if((gapToInput(i,0) <= 2) && (gapToInput(j,1) <=2) && (gapToInput(k,2) <=2)){
							count++;
						} else if((gapToMaster(i,0) <= 2) && (gapToMaster(j,1) <=2) && (gapToMaster(k,2) <=2)){
							count++;
						}
					}
				}
			}
		}
		out.println(count);
		out.close();
	}
	private static int gapToInput(int position, int i) {
		int gap1,gap2;
		gap1=gap2=0;
		if(position == input[i]){
			return 0;
		} else if(position < input[i]){
			gap1=Math.abs(position - input[i]);
			gap2= position + Math.abs(N-input[i]);
		} else if(position > input[i]){
			gap1 = Math.abs(position-input[i]);
			gap2 = Math.abs(position - N) + input[i];
		}
		return Math.min(gap1, gap2);
	}
	private static int gapToMaster(int position, int i) {
		int gap1,gap2;
		gap1=gap2=0;
		if(position == master[i]){
			return 0;
		} else if(position < master[i]){
			gap1=Math.abs(position - master[i]);
			gap2= position + Math.abs(N-master[i]);
		} else if(position > master[i]){
			gap1 = Math.abs(position-master[i]);
			gap2 = Math.abs(position - N) + master[i];
		}
		return Math.min(gap1, gap2);
	}
	static int gap(int position, int i){
		return Math.min(gapToMaster(position, i), gapToInput(position, i));
	}
}