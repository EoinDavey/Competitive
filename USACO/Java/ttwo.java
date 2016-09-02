import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.StringTokenizer;

/*
ID: eoin.da1
LANG: JAVA
TASK: ttwo
*/

public class ttwo {
	
	PrintWriter out;
	
	char[][] board = new char[10][10];
	int limit = 10000;
	final int NORTH = 0;
	final int SOUTH  = 1;
	final int WEST = 2;
	final int EAST = 3;
	
	public static void main(String[] args) throws IOException{
		ttwo main = new ttwo();
		main.run();
	}
	
	public void run()throws IOException{
		readIn();
		loop();
		stop();
	}
	
	void loop(){
		int[] fPos,cPos;
		fPos=cPos = new int[]{};
		int fDir,cDir;
		fDir = cDir = NORTH;
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 10; j++){
				if(board[i][j] == 'F') fPos = new int[]{i,j};
				if(board[i][j]=='C')cPos = new int[]{i,j};
			}
		}
		//simulate
		int dX,dY,newX,newY,count;
		dX = dY = count=1;
		boolean reached = false;
		while(count<limit){
			//cow
			dX=dY=0;
			switch(cDir){
			case NORTH:
				dX = -1;
				break;
			case SOUTH:
				dX = 1;
				break;
			case WEST:
				dY = -1;
				break;
			case EAST:
				dY = 1;
				break;
			}
			newX = cPos[0] + dX;
			newY = cPos[1] + dY;
			if(newX >= 0&&newX < 10&&newY>=0&&newY<10){
				if(board[newX][newY]!='*'){
					cPos = new int[]{newX,newY};
				} else {
					cDir = rotate(cDir);
				}
			} else {
				cDir = rotate(cDir);
			}
			//farmer
			dX=dY = 0;
			switch(fDir){
			case NORTH:
				dX = -1;
				break;
			case SOUTH:
				dX = 1;
				break;
			case WEST:
				dY = -1;
				break;
			case EAST:
				dY = 1;
				break;
			}
			newX = fPos[0] + dX;
			newY = fPos[1] + dY;
			if(newX >= 0&&newX < 10&&newY>=0&&newY<10){
				if(board[newX][newY]!='*'){
					fPos = new int[]{newX,newY};
				} else {
					fDir = rotate(fDir);
				}
			} else {
				fDir = rotate(fDir);
			}
			if(fPos[0]==cPos[0]&&fPos[1]==cPos[1]){
				reached = true;
				print("" + count);
				break;
			}
			count++;
		}
		if(!reached){
			print("" + 0);
		}
	}
	
	int rotate(int dirIn){
		switch(dirIn){
		case NORTH:
			return EAST;
		case SOUTH:
			return WEST;
		case EAST:
			return SOUTH;
		case WEST:
			return NORTH;
		default:
			return NORTH;
		}
	}
	
	void readIn() throws IOException{
		BufferedReader reader = new BufferedReader(new FileReader("ttwo.in"));
		out = new PrintWriter(new FileWriter("ttwo.out"));
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String in;
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 10; j++){
				board[i][j] = (char)reader.read();
			}
			reader.readLine();
		}
	}
	
	void stop(){
		out.close();
	}
	
	void print(String s){ 
		out.println(s);
	}
}
