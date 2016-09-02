import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Scanner;
/*
ID: eoin.da1
LANG: JAVA
PROG: crypt1
 */

class crypt1 {
	static int N;
	static int[] digits;
	public static void main(String[] args) throws IOException{
		//Scanner scanner = new Scanner(System.in);
		Scanner scanner = new Scanner(new FileReader("crypt1.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("crypt1.out")));
		N = scanner.nextInt();
		digits = new int[N];
		for(int i = 0; i < N; i++){
			digits[i] = scanner.nextInt();
		}
		//for each abc
		//against each e
		//against each d
		//
		Arrays.sort(digits);
		int i,j,k,l,m,e,d,abc,productE,productD, finalSum, count;
		//for each abc
		count = 0;
		for(i = 0; i < N; i++){
			for(j=0; j<N;j++){
				for(k=0;k<N;k++){
					abc = Integer.parseInt("" + digits[i] + digits[j] + digits[k]);
					//for each e
					for(l = 0; l < N;l++){
						e = digits[l];
						productE = abc * e;
						if(Integer.toString(productE).length() > 3){
							break;
						}
						if(!usesDigits(productE)){
							continue;
						}
						//for each d
						for(m=0;m<N;m++){
							d=digits[m];
							productD = abc*d;
							if(Integer.toString(productD).length() > 3){
								break;
							}
							if(!usesDigits(productD)){
								continue;
							}
							finalSum = 10*productD + productE;
							if(usesDigits(finalSum)){
								//System.out.println(finalSum);
								count++;
							}
						}
					}
				}
			}
		}
		out.println(count);
		out.close();
	}
	private static boolean usesDigits(int finalSum) {
		boolean valid = true;
		char[] input = Integer.toString(finalSum).toCharArray();
		for(int i = 0; i < input.length; i++){
			if(Arrays.binarySearch(digits, Character.getNumericValue(input[i])) < 0){
				valid = false;
				break;
			}
		}
		return valid;
	}
	
}