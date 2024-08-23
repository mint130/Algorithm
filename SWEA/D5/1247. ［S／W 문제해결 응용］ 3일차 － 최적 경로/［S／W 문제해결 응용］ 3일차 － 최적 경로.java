import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

	static class Point{
		int x, y;
		public Point(int x, int y) {
			this.x=x; 
			this.y=y;
		}
		int dist(Point p) { //거리 계산
			return Math.abs(this.x-p.x)+Math.abs(this.y-p.y);
		}

	}
	static int T, N, ans;
	static Point h, c, arr[];
	static boolean visit[];
	static void dfs(int depth, Point cur, int dist) {
		//회사에서 출발, 집도착  
		//현재 좌표 point	
		if(dist>ans) return; //최단 경로를 구하므로 가지치기
		if(depth==N) {
            //N개 모두를 돌았으면 마지막 cur에서 집까지의 거리
			ans=Math.min(ans, dist+cur.dist(h));
			return;
		}
		for(int i=0;i<N;i++) {
			Point nxt = arr[i];
			if(!visit[i]) {
				visit[i]=true;
				dfs(depth+1, nxt, dist+cur.dist(nxt));
				visit[i]=false;
			}
			
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		T = Integer.parseInt(st.nextToken());
		for(int tc = 1;tc <= T;tc++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			arr = new Point[N];
			visit = new boolean[N];
			ans=987654321;
			st = new StringTokenizer(br.readLine());
			c = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
			h = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
			for(int i=0;i<N;i++) {
				arr[i]= new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
			}
			dfs(0,c,0);
			System.out.println("#"+tc+" "+ans);
		}

	}

}
