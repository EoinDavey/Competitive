import java.util.Arrays;
import java.util.Scanner;
import java.io.*;
import java.lang.*;
/*
ID: eoin.da1
LANG: JAVA
PROG: milk2
 */

class milk2 {
	public static void main(String[] args) throws IOException{
		//Scanner scanner = new Scanner(System.in);
		Scanner scanner = new Scanner(new FileReader("milk2.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("milk2.out")));
		int N = scanner.nextInt();
		long start,end,lastTime, streak, gap,maxStreak,maxGap;
		start = end = lastTime = streak = gap = maxStreak=maxGap=0;
		Farmer[] farmers = new Farmer[N];
		for(int i=0;i<N;i++){
			start = scanner.nextLong();
			end = scanner.nextLong();
			farmers[i] = new Farmer(start,end);
		}
		Arrays.sort(farmers);
		lastTime = farmers[0].getEnd();
		maxStreak = streak = farmers[0].getEnd() - farmers[0].getStart();
		for(int i = 1; i < N; i++){
			gap = 0;
			if(farmers[i].getStart()<=lastTime){
				if(farmers[i].getEnd() > lastTime){
					streak += farmers[i].getEnd() - lastTime;
				}
			} else {
				gap = farmers[i].getStart() - lastTime;
				streak = farmers[i].getEnd() - farmers[i].getStart();
			}
			lastTime = (farmers[i].getEnd() > lastTime) ? farmers[i].getEnd():lastTime;
			maxGap = (gap>maxGap) ? gap:maxGap;
			maxStreak = (streak>maxStreak) ? streak:maxStreak;
		}
		out.println(maxStreak + " " + maxGap);
		out.close();
	}
}

class Farmer implements Comparable<Farmer>{
	private long startTime;
	private long endTime;
	public Farmer(long start, long end){
		startTime = start;
		endTime = end;
	}
	
	@Override
	public String toString(){
		return Long.toString(this.startTime);
	}
	
	public long getStart(){
		return startTime;
	}
	public long getEnd(){
		return endTime;
	}

	@Override
	public int compareTo(Farmer arg0) {
		return new Long(this.startTime).compareTo(arg0.getStart());
	}
}