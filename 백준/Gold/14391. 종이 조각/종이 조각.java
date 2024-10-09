import java.util.Scanner;

public class Main {

	static int n, m, board[][], ans;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n=sc.nextInt();
		m=sc.nextInt();
		board=new int[n][m];
		for(int i=0;i<n;i++) {
			String s = sc.next();
			for(int j=0;j<m;j++) {
				board[i][j]=s.charAt(j)-'0';
			}
		}
		
		
		for(int k=0;k<(1<<(n*m));k++) {
			//0000 0000 0000 0000 부터 1111 1111 1111 1111 까지
			
			int sum = 0;
			//k가 0이면 가로 
			for(int i=0;i<n;i++) {
				int cur=0;
				for(int j=0;j<m;j++) {
					int num = i*m + j; //현재 숫자 
					if((k&(1<<num))==0) {
						//지금 숫자와 k가 0이면 가로 -> j가 커짐 
						cur=cur*10 + board[i][j];
					}
					else {
						sum+=cur;
						cur = 0;
						
					}
				}
				sum+=cur;
			}
			
			//k가 1이면 세로 
			for(int j=0;j<m;j++) {
				int cur = 0;
				for(int i=0;i<n;i++) {
					int num = i*m + j; //현재 숫자 
					if((k&(1<<num))!=0) {
						//1이면 세로 -> i가 커짐 
						cur= cur*10 + board[i][j];
					}
					else {
						sum+=cur;
						cur = 0;
					};
				}
				sum+=cur;
			}
		
			ans = Math.max(sum, ans);
		}
		
		System.out.println(ans);
	}

}
