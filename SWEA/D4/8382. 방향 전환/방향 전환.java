import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.Scanner;

public class Solution {

	static int T, x1, y1, x2, y2;
	static int dist[][][];
	static int dx[]= {1, -1, 0, 0};
	static int dy[]= {0, 0, 1, -1}; //0 1 상하 2 3 좌 우 
	static class point{
		int x, y, dir;
		public point(int x, int y, int dir) {
			this.x=x;
			this.y=y;
			this.dir=dir;
		}
	}
	//dir 0은 가로 dir 1은 세로 
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		T=sc.nextInt();
		for(int tc=1;tc<=T;tc++) {
			dist=new int[202][202][2];
			for(int i=0;i<202;i++) {
				for(int j=0;j<202;j++){
					dist[i][j][0]=-1;
					dist[i][j][1]=-1;
				}
			}
			x1=sc.nextInt()+100;
			y1=sc.nextInt()+100;
			x2=sc.nextInt()+100;
			y2=sc.nextInt()+100;
			Queue<point> q= new ArrayDeque<>();
			q.add(new point(x1, y1, 0));
			q.add(new point(x1, y1, 1));
			dist[x1][y1][0]=0;
			dist[x1][y1][1]=0;
			while(!q.isEmpty()) {
				point p=q.poll();
				int x=p.x;
				int y=p.y;
				int dir=p.dir;
				if(x==x2 && y==y2) {
					int a=dist[x][y][0];
					int b=dist[x][y][1];
					int min=Integer.MAX_VALUE;
				
					if(a!=-1 && b!=-1) min=Math.min(a, b);
					else if(a==-1) min=b;
					else if(b==-1) min=a;
					
					System.out.println("#"+tc+" "+min);
					break;
				}
				if(dir==0) {
					//세로로 이동 
					for(int i=0;i<2;i++) {
						int nx=x+dx[i];
						int ny=y+dy[i];
						if(nx<0||nx>200||ny<0||ny>200) continue;
						if(dist[nx][ny][1]!=-1) continue;
						dist[nx][ny][1]=dist[x][y][0]+1;
						q.add(new point(nx, ny, 1));
					}
				}
				else {
					//가로로 이동 
					for(int i=2;i<4;i++) {
						int nx=x+dx[i];
						int ny=y+dy[i];
						if(nx<0||nx>200||ny<0||ny>200) continue;
						if(dist[nx][ny][0]!=-1) continue;
						dist[nx][ny][0]=dist[x][y][1]+1;
						q.add(new point(nx, ny, 0));
					}
				}
			}
			
		}
	}

}
