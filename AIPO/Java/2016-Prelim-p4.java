import java.util.*;
import java.lang.*;
import java.io.*;

class p4
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner scanner = new Scanner(new InputStreamReader(System.in));
		int n = scanner.nextInt();
		int[] nodes = new int[n];
		for(int i = 0; i < n; i++){
			nodes[i] = scanner.nextInt();
		}
		int height,index,current;
		for(int i = 0; i < n; i++){
			height=current=index=0;
			index=i;
			while(true){
				current = nodes[index];
				if(current == 0 || current == -1){
					break;
				} else {
					height++;
					index = current-1;
				}
			}
			System.out.println(height);
		}
	}
}