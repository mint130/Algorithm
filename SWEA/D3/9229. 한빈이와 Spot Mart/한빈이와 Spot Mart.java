import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Solution {

	static int T, ans;
	static int N, M; //M은 무게 합
	static int arr[];
	static boolean check[];
	static void dfs(int depth, int sum, int idx) {
		
		if(sum>M) return;
		if(depth==2) {
			if(sum<=M) ans = Math.max(ans, sum);
			return;
		}
		for(int i=idx;i<N;i++) {
			if(!check[i]) {
				check[i]=true;
				dfs(depth+1, sum+arr[i], i+1);
				check[i]=false;
			}
		}
		
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		T = Integer.parseInt(st.nextToken());
		for(int tc=1;tc<=T;tc++) {
			ans = -1;
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			arr = new int[N];
			check = new boolean[N];
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<N;i++) {
				arr[i]=Integer.parseInt(st.nextToken());
			}
			dfs(0, 0, 0);
			System.out.println("#"+tc+" "+ans);
		}
		
	}

}
