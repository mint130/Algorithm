import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	static int N, k, len; 
	static void func(int leftLen, int fullLen, int idx, int k) {
		if(fullLen==3) {
			if(idx==1) System.out.println("m");
			else System.out.println("o");
			return;
		}
		//leftLen+(k+3)+leftLen
		if(idx>leftLen+k+3) {
			//오른쪽으로
			//idx=idx-(leftLen+k+3)
			//leftLen=(leftLen-(k+3))/2
			k--;
			func((leftLen-(k+3))/2, leftLen, idx-(leftLen+k+1+3), k);
		}
		else if(idx>leftLen) {
			//중간 
			if(idx==leftLen+1) {
				System.out.println("m");
			}
			else System.out.println("o");
			return;
		}
		else if(idx<=leftLen) {
			//왼쪽 
			k--;
			func((leftLen-(k+3))/2, leftLen, idx, k);
		}
	}
	public static void main(String[] args) {
		//moo게임 
		Scanner sc =new Scanner(System.in);
		N=sc.nextInt();
		int k=0;
		int len=3;
		while(true) {
			if(len>=N) {
				break;
			}
			k++;
			len=len*2+k+3;	
		}
		func((len-(k+3))/2, len, N, k);

	}

}
