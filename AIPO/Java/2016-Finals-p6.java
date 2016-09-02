import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;


public class p6 {
	
	final long INF = (long) Math.pow(10,9);
	
	long N;
	long[] digits;

	public static void main(String[] args) throws IOException {
		p6 main = new p6();
		main.run();
	}
	
	void run() throws IOException{
		readIn();
		stop();
	}
	
	long count(long n){
		/*
		calculates values the naive way, used to check answers
		*/
		long units, tens,hundreds,thousands;
		units=tens=hundreds=thousands=0;
		for(int i = 0; i <= n;i++){
			String s = Integer.toString(i);
			units+= Character.getNumericValue(s.charAt(s.length()-1));
			if(s.length()>1){
				tens+=Character.getNumericValue(s.charAt(s.length()-2));
			}
			if(s.length()>2){
				hundreds+=Character.getNumericValue(s.charAt(s.length()-3));
			}
			if(s.length()>3){
				thousands+=Character.getNumericValue(s.charAt(s.length()-4));
			}
		}
		//print((hundreds+tens+units+thousands)+ thousands+ " "+ hundreds+" " + tens + " " + units + " ");
		long test = 0;
		return (hundreds+tens+units+thousands);
	}
	
	long v2(long n){
		//calculates values efficiently
		String s = Long.toString(n);
		long[] store = new long[17];
		long[] remStore = new long[17];
		long full,rem,val,error,pow;
		boolean adjust = false; //adjust is only true if the number ends in a 0
		if(s.charAt(s.length()-1)=='0') adjust = true;
		for(int i = 0; i < s.length(); i++){
			pow = (long) Math.pow(10, i); //the power of 10 we're dealing with
			full = (long) Math.floor(n/(pow*10)); //how many full sets of 0 to 9 there are at this level
			rem = (n-(full*(pow*10)))/pow; //remainder of incomplete sets of 0 to 9
			remStore[i]=rem; //store remainder
			//45 is the sum of 0 to 9
			if(i==0)val = (45*full*pow) + pow*sum(rem); //calculation is slightly different for units column
			else val=(45*full*pow) + pow*sum(rem-1); //sum function returns value of the sum of 0 to n;
			error = 0; //error adjusts for previous left over remainders
			for(int j = i-1; j>=0;j--){
				error += (remStore[j] * Math.pow(10, j));
			}
			if(error>0)error++; //if the error is not 0, it must be increased by one
			error*=rem; //multiply by the remainder
			val+=error; //add to final value
			store[i] = val; //store final value
			//print(""+val);
		}
		long sum = 0; 
		//add up all values
		for(int i = 0; i < store.length; i++){
			sum+=store[i];
		}
		if(adjust&&s.length()>=2){ //if the number ends in a 0 and is not == 0
			int j = 0;
			//go through the number from right to left (units->tens...etc) until you reach a number that is not 0.
			while(adjust){
				if(s.charAt(s.length()-j-1)!='0'){
					sum+=Character.getNumericValue(s.charAt(s.length()-j-1)); // Add first number that is not 0
					adjust = false;
				} else j++;
			}
		}
		//print(""+sum);
		return sum;
	}
	
	long sum(long n){ //return value of sum 0->n
		return (n)*(n+1)/2;
	}
	
	void readIn() throws IOException{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String in;
		
		N=Long.parseLong(reader.readLine());
		print(""+v2(N));
		//count(N);
		/*for(long i = 0; i <=N;i++){
			try{
				if(v2(i)!=count(i)){
					print(i+"; " + v2(i) + ";" +count(i));
				}
			}catch(Exception e){
				System.out.println(i);
				e.printStackTrace();
			}
		}*/
		
		reader.close();
	}
	
	void stop(){
		
	}
	
	double toRadians(double deg){
		return deg*(Math.PI/180);
	}
	
	void print(String s){
		System.out.println(s);
	}

}

