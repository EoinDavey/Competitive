import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
/*
ID: eoin.da1
LANG: JAVA
PROG: transform
 */

class transform {
	final static char black = '@';
	final static char white = '-';
	static char[][] inSquare, outSquare;
	public static void main(String[] args) throws IOException{
		//Scanner scanner = new Scanner(System.in);
		Scanner scanner = new Scanner(new FileReader("transform.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("transform.out")));
		int N = scanner.nextInt();
		inSquare= new char[N][N];
		outSquare= new char[N][N];
		scanner.nextLine();
		String line;
		for(int i = 0; i < N; i++){
			line = scanner.nextLine();
			for(int j = 0; j < N; j++){
				inSquare[i][j] = line.charAt(j);
			}
		}
		for(int i = 0; i < N; i++){
			line = scanner.nextLine();
			for(int j = 0; j < N; j++){
				outSquare[i][j] = line.charAt(j);
			}
		}
		if(check(rotate90(inSquare), outSquare)) out.println(1);
		else if(check(rotate180(inSquare),outSquare)) out.println(2);
		else if(check(rotate270(inSquare),outSquare)) out.println(3);
		else if(check(reflect(inSquare), outSquare)){
			out.println(4);
		} else {
			char[][] reflected = reflect(inSquare);
			if(check(rotate90(reflected), outSquare)) out.println(5);
			else if(check(rotate180(reflected),outSquare)) out.println(5);
			else if(check(rotate270(reflected),outSquare)){ 
				out.print(5);
			} else {
				if(check(inSquare, outSquare))out.println(6);
				else out.println(7);
			}
		}
		out.close();
	}
	public static boolean check(char[][] in, char[][] out){
		for(int i = 0; i < in.length; i++){
			for(int j=0; j < in.length; j++){
				if(in[i][j] != out[i][j]){
					return false;
				}
			}
		}
		return true;
	}
	public static char[][] rotate90(char[][] in){
		char[][] out = new char[in.length][in.length];
		for(int i = 0; i < in.length; i++){
			for(int j = 0; j < in.length; j++){
				out[i][j] = in[in.length-j-1][i];
			}
		}
		return out;
	}
	public static char[][] rotate180(char[][] in){
		char[][] out = new char[in.length][in.length];
		for(int i = 0; i < in.length; i++){
			for(int j = 0; j < in.length; j++){
				out[i][j] = in[in.length-i-1][in.length-j-1];
			}
		}
		return out;
	}
	public static char[][] rotate270(char[][] in){
		char[][] out = new char[in.length][in.length];
		for(int i = 0; i < in.length; i++){
			for(int j = 0; j < in.length; j++){
				out[i][j] = in[j][in.length-i-1];
			}
		}
		return out;
	}
	public static char[][] reflect(char[][] in){
		char[][] out = new char[in.length][in.length];
		for(int i = 0; i < in.length; i++){
			for(int j=0;j<in.length;j++){
				out[i][j] = in[i][in.length-j-1];
			}
		}
		return out;
	}
}