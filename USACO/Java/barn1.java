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
PROG: barn1
 */

class barn1 {
	static LinkedList<Board> boards;
	static int[] stalls;
	static PrintWriter out;
	public static void main(String[] args) throws IOException{
		//Scanner scanner = new Scanner(System.in);
		Scanner scanner = new Scanner(new FileReader("barn1.in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter("barn1.out")));
		int maxBoards = scanner.nextInt();
		int nStalls = scanner.nextInt();
		int nCows = scanner.nextInt();stalls = new int[nCows];
		boards = new LinkedList<Board>();
		for(int i = 0; i < nCows; i++){
			stalls[i] = scanner.nextInt();
		}
		if(maxBoards > nCows){
			out.println(nCows);
			out.close();
			System.exit(0);
		}
		Arrays.sort(stalls);
		/*
		 * Cover all cows
		 * find largest gap and split board that covers it
		 */
		boards.add(new Board(0, stalls.length-1));
		while(boards.size() < maxBoards){
			Board b = findBiggestGap();
			splitBoard(b);
		}
		displayBoards();
		out.close();
	}
	private static void displayBoards() {
		ListIterator<Board> iterator = boards.listIterator();
		int sum = 0;
		while(iterator.hasNext()){
			Board b = iterator.next();
			sum+= stalls[b.end] - stalls[b.start] + 1;
		}
		out.println(sum);
	}
	private static void splitBoard(Board b) {
		int index = 0;
		int maxGap = 0;
		for(int i = b.start; i < b.end; i++){
			int gap = stalls[i+1] - stalls[i];
			if(gap > maxGap){
				maxGap = gap;
				index = i;
			}
		}
		Board newBoard = new Board(index + 1, b.end);
		b.end = index;
		index = boards.indexOf(b);
		boards.add(index+1, newBoard);
	}
	private static Board findBiggestGap() {
		ListIterator<Board> iterator = boards.listIterator();
		int maxGap =0;
		Board gapBoard = null;
		Board currentBoard;
		while(iterator.hasNext()){
			currentBoard = iterator.next();
			for(int i = currentBoard.start; i < currentBoard.end; i++){
				int gap = stalls[i+1] - stalls[i];
				if(gap > maxGap){
					maxGap = gap;
					gapBoard = currentBoard;
				}
			}
		}
		return gapBoard;
	}
	
}

class Board{
	int start;
	int end;
	Board(int start, int end){
		this.start = start;
		this.end = end;
	}
}