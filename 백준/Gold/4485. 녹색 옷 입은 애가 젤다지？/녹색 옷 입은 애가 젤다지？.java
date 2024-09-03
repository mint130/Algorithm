import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static int N, ans;
	static final int INF=Integer.MAX_VALUE;
	static int map[][], dist[][];
	static int dx[]= {1, 0, -1, 0};
	static int dy[]= {0, 1, 0, -1};
	static boolean visit[][];
	static class Data implements Comparable<Data>{
		int x, y, w;
		public Data(int x, int y, int w) {
			this.x=x;
			this.y=y;
			this.w=w;
		}
		@Override
		public int compareTo(Data o) {
			// TODO Auto-generated method stub
			return Integer.compare(this.w, o.w);
		}
	}
	public static void main(String[] args) throws IOException {
		//0, 0에서 n-1, n-1까지 도달하는데 걸리는 최소 금액 -> 다익스트라 
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int t=1;
		while(true) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			N=Integer.parseInt(st.nextToken());
			if(N==0) {
				System.out.println(sb);
				return;
			}
			ans=0;
			map=new int[N][N];
			dist=new int[N][N];
			visit=new boolean[N][N];
			for(int i=0;i<N;i++) {
				Arrays.fill(dist[i], INF);
			}
			//초기화 
			for(int i=0;i<N;i++) {
				st=new StringTokenizer(br.readLine());
				for(int j=0;j<N;j++) {
					map[i][j]=Integer.parseInt(st.nextToken());
				}
			}
			ans=dijkstra();
			sb.append("Problem ").append(t).append(": ").append(ans).append("\n");
			t++;
		}

	}
	static int dijkstra() {
		//0, 0부터 시작~N-1, N-1에 도달하면 종료  
		dist[0][0]=map[0][0];
		PriorityQueue<Data> pq = new PriorityQueue<>();
		pq.add(new Data(0, 0, dist[0][0])); //0, 0에서 출발 
		while(!pq.isEmpty()) {
			Data d=pq.poll();
			int x=d.x;
			int y=d.y;
			int w=d.w;
			
			if(visit[x][y]) continue;
			visit[x][y]=true;
			if(x==N-1 && y==N-1) return w;
			for(int dir=0;dir<4;dir++) {
				int nx=x+dx[dir];
				int ny=y+dy[dir];
				if(nx<0||nx>=N||ny<0||ny>=N) continue;
				if(visit[nx][ny]) continue;
				if(dist[nx][ny]>w+map[nx][ny]) {
					//현재 d를 거쳐가는 것이 더 유리하다 
					dist[nx][ny]=w+map[nx][ny];
					pq.add(new Data(nx, ny, dist[nx][ny]));
				}
			}
			
			
		}
		return 0;
		
		
	}

}
