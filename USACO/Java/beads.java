import java.util.Scanner;
import java.io.*;
/*
ID: eoin.da1
LANG: JAVA
PROG: beads
 */
class beads{
	
	static char red = 'r';
	static char blue = 'b';
	static char white = 'w';
	public static void main(String[] args) throws IOException{
		//Scanner scanner = new Scanner(System.in);
		Scanner scanner = new Scanner(new FileReader("beads.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("beads.out")));
		int N = scanner.nextInt();
		String input = scanner.next();
		char[] beads = input.toCharArray();
		boolean[] collected = new boolean[beads.length];
		char fStart,rStart;
		int max,k,fCount,rCount,l,total;
		max=fCount=rCount=0;
		/*
		 * i is the dividing point, 0 before bead 0, 1 before bead 1
		 * k is the forward bead being checked
		 * l is the reverse bead being checked
		 */
		for(int i = 0; i < N; i++){
			fStart = beads[i];
			rStart = (i>0) ? beads[i-1]:beads[N-1];
			fCount = rCount = 0;
			collected = new boolean[beads.length];
			for(int j = 0; j<N; j++){
				k = (i+j >= N) ? (j+i)-N:i+j;
				if(fStart == white && j==0){
					fCount++;
					continue;
				} else {
					if(fStart == white && j>0){
						fStart = beads[k];
					}
					if(beads[k] != fStart && beads[k] != white){
						break;
					} else {
						collected[k] = true;
						fCount += 1;
					}
				}
			}
			for(int j = 0; j<N;j++){
				l = (i-j-1 < 0) ? N+(i-j-1): i-j-1;
				if(rStart == white && j==0){
					if(!collected[l]){
						rCount++;
						continue;
					} else {
						break;
					}
				}
				if(rStart == white && j>0){
					rStart = beads[l];
				}
				if(beads[l] != rStart && beads[l] != white){
					break;
				} else {
					if(!collected[l]){
						rCount++;
					}
				}
			}
			total = fCount + rCount;
			if(total > max){
				max = total;
			}
		}
		out.println(max);
		out.close();
	}
}