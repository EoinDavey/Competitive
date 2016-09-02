/*
ID: eoin.da1
LANG: JAVA
PROG: gift1
*/
import java.io.*;
import java.util.*;

class gift1 {
	  public static void main (String [] args) throws IOException {
		Scanner scanner = new Scanner(new FileReader("gift1.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("gift1.out")));
		int N = scanner.nextInt();
		scanner.nextLine();
		String[] names = new String[N];
		HashMap<String, Integer> map = new HashMap<String,Integer>();
		String input = "";
		for(int i = 0; i < N; i++){
			input = scanner.nextLine();
			names[i] = input;
			map.put(input,0);
		}
		int money, div, remainder,inc;
		money=div=remainder=inc=0;
		String giver = "";
		String receiver = "";
		for(int i = 0; i < N; i++){
			giver = scanner.nextLine();
			money=scanner.nextInt();
			div=scanner.nextInt();
			scanner.nextLine();
			if(money == 0|| div == 0){
				if(div != 0){
					for(int j = 0; j < div; j++){
						scanner.nextLine();
					}
				}
				continue;
			} else {
				
			}
			remainder = money % div;
			map.put(giver, map.get(giver) - (money-remainder));
			inc = (money-remainder) / div;
			for(int j=0;j<div;j++){
				receiver = scanner.nextLine();
				map.put(receiver, map.get(receiver) + inc);
			}
		}
		for(int i = 0; i < N; i++){
			out.println(names[i] + " " + map.get(names[i]));
		}
		out.close();
	}
}