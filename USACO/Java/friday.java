/*
ID: eoin.da1
LANG: JAVA
PROG: friday
*/
import java.io.*;
import java.util.*;

class  friday{
  public static void main (String [] args) throws IOException {
    Scanner scanner = new Scanner(new FileReader("friday.in"));
	PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("friday.out")));
	  int[] days = new int[7];
	  int n = scanner.nextInt();
	  int current_day = 2;
	  /* 
	   * i is years
	   * j is months
	   * k is days/month
	   */
	  int k_limit = 0;
	  for(int i = 1900; i < 1900 + n;i++){
		  for(int j = 0; j < 12; j++){
			  switch(j){
			  case 0:
				  k_limit = 31;break;
			  case 1:
				  k_limit=28;
				  if(i % 4 == 0){
					  if(i % 100 == 0 && i % 400 != 0){
						  break;
					  }
					 k_limit = 29;
				  }
				  break;
			  case 2:
				  k_limit=31;break;
			  case 3:
				  k_limit=30;break;
			  case 4:
				  k_limit=31;break;
			  case 5:
				  k_limit=30;break;
			  case 6:
				  k_limit=31;break;
			  case 7:
				  k_limit=31;break;
			  case 8:
				  k_limit=30;break;
			  case 9:
				  k_limit=31;break;
			  case 10:
				  k_limit=30;break;
			  case 11:
				  k_limit=31;break;
			  }
			  for(int k =0; k < k_limit; k++){
				  if(k==12){
					  days[current_day] = days[current_day] + 1;
				  }
				  current_day = nextDay(current_day);
			  }
		  }
	  }
	  for(int i = 0; i < 7; i++){
		  if(i == 6){
			  out.println(days[i]);
		  } else {
			out.print(days[i] + " ");
		  }
	  }
	  out.close();
  }
  
  private static int nextDay(int n){
	  if(n == 6) return 0;
	  return n+1;
  }
}