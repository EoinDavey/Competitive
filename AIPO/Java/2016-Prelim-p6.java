import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class p6
{
	final static long mod_limit = (long) Math.pow(10,9) + 7;
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner scanner = new Scanner(new InputStreamReader(System.in));
		int t = scanner.nextInt();
		int n,k,result;
		BigInteger top,bottom,temp;
		for(int i = 0; i < t; i++){
			n=k=0;
			result=0;
			n=scanner.nextInt();
			k=scanner.nextInt();
			temp=top=bottom=BigInteger.ONE;
			for(int j=(n-k+1); j <= n; j++){
				top = top.multiply(BigInteger.valueOf(j));
			}
			for(int j=k; j>1; j--){
				bottom = bottom.multiply(BigInteger.valueOf(j));
			}
			temp = top.divide(bottom);
			temp = temp.mod(BigInteger.valueOf(mod_limit));
			System.out.println(temp.toString());
		}
	}
}