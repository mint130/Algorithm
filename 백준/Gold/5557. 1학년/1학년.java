import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int arr[]=new int[n];
		st=new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			arr[i]=Integer.parseInt(st.nextToken());
		}
		long dp[][]=new long[n][21]; //dp[i][j]는 i번째 인덱스에서 합 j를 만들 수 있는 경우의 수 갯수 저장
		dp[0][arr[0]]=1;
		for(int i=1;i<=n-2;i++) {
			for(int j=0;j<=20;j++) {
				//j는 합
				if(dp[i-1][j]!=0) {
					//직전 인덱스까지 만들어진 합 j가 존재한다면
					if(j+arr[i]<=20) dp[i][j+arr[i]]+=dp[i-1][j]; //합 j에 현재 arr[i] 더했을 때 20보다 작거나 같으면 경우의 수 더함
					if(j-arr[i]>=0) dp[i][j-arr[i]]+=dp[i-1][j]; //합 j에 현재 arr[i] 뺐을 때 0보다 크거나 같으면 경우의 수 더함
				}
			}
		}
		System.out.println(dp[n-2][arr[n-1]]);
		//마지막(n-1)-1번째 순서에서 마지막 숫자를 합으로 만들 수 있는 경우의 수 
	}

}
