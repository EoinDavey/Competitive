import java.util.ArrayList;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		String S  = s.nextLine();
		int E;
		E = s.nextInt();
		s.nextLine();
		String line;
		ArrayList<String[]> list = new ArrayList<String[]>();
		for(int i = 0; i < E; i++){
			line = s.nextLine();
			String[] ends = line.split(" ");
			for(int j = 0; j < ends.length; j++){
				if(S.endsWith(ends[j])){
					list.add(ends);
					break;
				}
			}
		}
		int P=0;
		P = s.nextInt();
		boolean b = false;
		s.nextLine();
		for(int i = 0; i < P; i++){
			b=false;
			line = s.nextLine();
			for(int j = 0; j < list.size(); j++){
				String[] a = list.get(j);
				for(int k = 0; k < a.length; k++){
					if(line.endsWith(a[k])){b=true;}
				}
			}
			if(b){System.out.println("YES");
			} else {System.out.println("NO");
			}
		}
		s.close();
	}

}
