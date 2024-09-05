import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int T, N, M;
	static int arr[][]; //in, out
	static ArrayList<Integer> v[];
	static boolean visit[];
	static void dfs(int start, int cur) {
		
		for(int nxt:v[cur]) {
			if(!visit[nxt]) {
				visit[nxt]=true;
				arr[start][nxt]=arr[start][cur]+1;
				dfs(start, nxt);
			}
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

	
			
		N=Integer.parseInt(st.nextToken());
		M=Integer.parseInt(st.nextToken());
			
		//visit=new boolean[N+1];
		arr=new int[N+1][N+1];
			
		v=new ArrayList[N+1];
		for(int i=1;i<=N;i++) {
			v[i]=new ArrayList<>();
		}
		
		for(int i=0;i<M;i++) {
			st=new StringTokenizer(br.readLine());
			int a, b;
			a=Integer.parseInt(st.nextToken());
			b=Integer.parseInt(st.nextToken());
			v[a].add(b);
		}
		for(int i=1;i<=N;i++) {
			visit=new boolean[N+1];
			visit[i]=true;
			dfs(i, i);
		}
		int taller[]=new int[N+1]; //자신보다 더 키가 큰 학생들 수 
		int smaller[]=new int[N+1]; //자신보다 더 키가 작은 학생들 수
		for(int i=1;i<=N;i++) {
			int cnt1=0;
			int cnt2=0;
			for(int j=1;j<=N;j++) {
				if(arr[i][j]!=0) cnt1++;
				if(arr[j][i]!=0) cnt2++;
			}
			taller[i]=cnt1;
			smaller[i]=cnt2;
		}
		int ans = 0;
		for(int i=1;i<=N;i++) {
			if(smaller[i]+taller[i]==N-1) ans++; //몇번째인지 알 수 있음 
		}
		System.out.println(ans);
	}

}