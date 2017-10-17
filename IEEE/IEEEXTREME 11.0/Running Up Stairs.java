import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public final static int MAXN = 22001;
	
	public static void main(String[] args) {
		BigInteger[] ways = new BigInteger[MAXN];
		ways[0] = BigInteger.ONE;
		ways[1] = BigInteger.ONE;
		for( int i = 2; i < MAXN; ++i ) {
			ways[i] = ways[i-1].add(ways[i-2]);
		}
		Scanner cin = new Scanner(System.in);
		int nTest = cin.nextInt();
		while( nTest-- > 0 ) {
			int n = cin.nextInt();
			System.out.println(ways[n]);
		}
	}

}
