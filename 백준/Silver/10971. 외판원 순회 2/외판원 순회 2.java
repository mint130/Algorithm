import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int dp[][];
	static int N, start;
	static boolean visit[];
	static long ans=Long.MAX_VALUE;
	static boolean all() {
		for(int i=0;i<N;i++) {
			if(!visit[i]) return false;
		}
		return true;
	}
	static void dfs(int cur, long cost) {
		if(all()) {
			if(dp[cur][start]!=0) ans=Math.min(ans, cost+dp[cur][start]);
			return;
		}
		for(int i=0;i<N;i++) {
			if(visit[i] || dp[cur][i]==0) continue;
			visit[i]=true;
			dfs(i, cost+dp[cur][i]);
			visit[i]=false;
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N=Integer.parseInt(st.nextToken());
		dp=new int[N][N];
		visit=new boolean[N];
		for(int i=0;i<N;i++) {
			st=new StringTokenizer(br.readLine());
			for(int j=0;j<N;j++) {
				dp[i][j]=Integer.parseInt(st.nextToken());
			}
		}
		visit[0]=true;
		dfs(0, 0);
		System.out.println(ans);
		
	}

}
