import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {

	//1 상하좌우  0 1 2 3 
	//2 상하  0 2  
	//3 좌우  1 3 
	//4 상우  1 2
	//5 하우  0 1
	//6 하좌  0 3
	//7 상좌  2 3
	static int dist[][];
	static int map[][];
	static int dx[]= {1, 0, -1, 0}; //하 우 상 좌 
	static int dy[]= {0, 1, 0, -1};
	static int d[][]=new int[8][];
	static class point{
		int x, y, pipe, dir;
		public point(int x, int y, int pipe, int dir) {
			this.x=x;
			this.y=y;
			this.pipe=pipe;
			this.dir=dir;
		}
	}
	static void init() {
		d[1]=new int[] {0, 1, 2, 3};
		d[2]=new int[] {0, 2};
		d[3]=new int[] {1, 3};
		d[4]=new int[] {1, 2};
		d[5]=new int[] {0, 1};
		d[6]=new int[] {0, 3};
		d[7]=new int[] {2, 3};
		
	}
	static int T, N, M, R, C, L; //N 세로 M 가로 R 시작행 C 시작열 L 시간 
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		T=Integer.parseInt(st.nextToken());
		for(int tc=1;tc<=T;tc++) {
			int ans = 0;
			init();
			st=new StringTokenizer(br.readLine());
			N=Integer.parseInt(st.nextToken());
			M=Integer.parseInt(st.nextToken());
			R=Integer.parseInt(st.nextToken());
			C=Integer.parseInt(st.nextToken());
			L=Integer.parseInt(st.nextToken());
			map=new int[N][M];
			dist=new int[N][M];
			dist[R][C]=1;
			Queue<point> q=new ArrayDeque<>();
			for(int i=0;i<N;i++) {
				st=new StringTokenizer(br.readLine());
				for(int j=0;j<M;j++) {
					map[i][j]=Integer.parseInt(st.nextToken());
				}
			}
			int num=map[R][C];
			
			for(int i=0;i<d[num].length;i++) {
				q.add(new point(R, C, map[R][C], d[num][i]));
			}
			//q.add(new point(R, C, map[R][C])); //map[R][C]에서 갈 수 있는 방향정보 추가 
			while(!q.isEmpty()) {
				point p = q.poll();
				int x = p.x;
				int y = p.y;
				int pipe = p.pipe;
				int dir=p.dir; //pipe로 온 방향 
				
				if(dist[x][y]==L) break;
				//시간 다 됨 
				
				int nx=x+dx[dir];
				int ny=y+dy[dir];
				if(nx<0||nx>=N||ny<0||ny>=M) continue;
				if(map[nx][ny]==0 || dist[nx][ny]!=0 && dist[nx][ny]<dist[x][y]+1) continue;
				int nxt=map[nx][ny];
				//pipe에 따라 갈 수 있는 방향이 나뉨
				if(dir==0) {
					//하 
					//map[nx][ny]가 1,2,4,7이면 이동 가능 
					if(nxt==1||nxt==2||nxt==4||nxt==7) {
						dist[nx][ny]=dist[x][y]+1;
						for(int i=0;i<d[nxt].length;i++) {
							q.add(new point(nx, ny, nxt, d[nxt][i]));
						}
					}
					
				}
				else if(dir==1) {
					//우 
					//map[nx][ny]가 1,3,6,7이면 이동 가능 
					if(nxt==1||nxt==3||nxt==6||nxt==7) {
						dist[nx][ny]=dist[x][y]+1;
						for(int i=0;i<d[nxt].length;i++) {
							q.add(new point(nx, ny, nxt, d[nxt][i]));
						}
					}
				}
				else if(dir==2) {
					//상 
					//map[nx][ny]가 1,2,5,6이면 이동 가능 
					if(nxt==1||nxt==2||nxt==5||nxt==6) {
						dist[nx][ny]=dist[x][y]+1;
						for(int i=0;i<d[nxt].length;i++) {
							q.add(new point(nx, ny, nxt, d[nxt][i]));
						}
					}
				}
				else if(dir==3) {
					//좌 
					//map[nx][ny]가 1,3,4,5이면 이동 가능 
					if(nxt==1||nxt==3||nxt==4||nxt==5) {
						dist[nx][ny]=dist[x][y]+1;
						for(int i=0;i<d[nxt].length;i++) {
							q.add(new point(nx, ny, nxt, d[nxt][i]));
						}
					}
				}
				
			}
			for(int i=0;i<N;i++) {
				for(int j=0;j<M;j++) {
					if(dist[i][j]!=0) ans++;
				}
			}
			System.out.println("#"+tc+" "+ans);
		}
	}

}
