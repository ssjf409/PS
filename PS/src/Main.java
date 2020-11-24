import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int M = sc.nextInt();
		
		boolean[] isDisable = new boolean[10];
		if(M > 0) {
			for(int i = 0; i < M; i++) {				
				isDisable[sc.nextInt()] = true;
			}
		}
		
		int minVal = 1000000;
		
		for(int i = 0; i <= 1000000; i++) {
			int term = Math.abs(N - 100);
			
			String str = String.valueOf(i);

			boolean canMake = true;
			for(int j = 0; j < str.length(); j++) {
				if(isDisable[str.charAt(j) - '0']) {
					canMake = false;
					break;
				}
			}
			
			if(canMake) {
				term = Math.min(term, str.length() + Math.abs(N - i));
			}
			
			if(term < minVal) {
				minVal = term;
			}
			
		}
		
		System.out.println(minVal);
		
		

		bw.flush();
		bw.close();
		
		
		br.close();
    }
}