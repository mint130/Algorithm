import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.Scanner;

public class Solution {

	static int T, N, A, B, C, D, ans;
	static int map[][]; //1은 장애물  
	static int dist[][]; 
	static int dx[]= {1, 0, -1, 0};
	static int dy[]= {0, 1, 0, -1};
	static boolean flag;
	static class Point{
		int x, y;
		public Point(int x, int y) {
			this.x=x;
			this.y=y;
		}
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		T=sc.nextInt();
		for(int tc=1;tc<=T;tc++) {
			N=sc.nextInt();
			ans=-1;
			map=new int[N][N];
			dist=new int[N][N];
			for(int i=0;i<N;i++) {
				Arrays.fill(dist[i], -1);
				for(int j=0;j<N;j++) {
					map[i][j]=sc.nextInt();

				}
			}
			A=sc.nextInt();
			B=sc.nextInt();
			C=sc.nextInt();
			D=sc.nextInt();
			Queue<Point> q=new ArrayDeque<>();
			dist[A][B]=0;
			q.add(new Point(A, B));
			while(!q.isEmpty()) {
				int x=q.peek().x;
				int y=q.peek().y;
				q.poll();
				if(x==C && y==D) {
					ans=dist[x][y];
					break;
				}
				for(int i=0;i<4;i++) {
					int nx=x+dx[i];
					int ny=y+dy[i];
					if(nx<0|| nx>=N||ny<0||ny>=N) continue;
					if(dist[nx][ny]!=-1 || map[nx][ny]==1) continue;
					dist[nx][ny]=dist[x][y]+1;
					q.add(new Point(nx, ny));
				}
				
			}
			System.out.println("#"+tc+" "+ans);
		
		}

	}

}
