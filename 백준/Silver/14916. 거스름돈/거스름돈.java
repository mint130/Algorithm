import java.util.Scanner;

public class Main{
	//dp로 풀이
	static int dp[]=new int[100001]; //dp[i]는 i원을 만들기위한 최소 동전 갯수
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		dp[1]=-1; //2와 5로 만들 수 없으면 -1
		dp[2]=1;
		dp[3]=-1;
		dp[4]=2;
		dp[5]=1;
		//6이상은 모든 수를 2와 5의 합으로 만들 수 있음
		for(int i=6;i<=n;i++) {
			if(dp[i-2]==-1) {
				//2원으로는 만들 수 없음
				dp[i]=dp[i-5]+1;
			}
			else if(dp[i-5]==-1) {
				//5원으로는 만들 수 없음
				dp[i]=dp[i-2]+1;
			}
			else {
				//2원으로 거슬러주는 경우, 5원으로 거슬러주는 경우 중 작은 것
				dp[i]=Math.min(dp[i-5]+1, dp[i-2]+1);
			}
		}
		System.out.println(dp[n]);
	}
}