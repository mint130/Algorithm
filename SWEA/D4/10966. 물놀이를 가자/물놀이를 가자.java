import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {
	static int T, ans;
	static int N, M;
	static char map[][];
	static int dist[][];
	static ArrayList<p> list; //물의 위치 저장
	static class p{
		int x, y;
		public p(int x, int y) {
			this.x=x;
			this.y=y;
		}
	}
	static int dx[]= {1, 0, -1, 0};
	static int dy[]= {0, 1, 0, -1};
	
	public static void main(String[] args) throws IOException {
		BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		T=Integer.parseInt(st.nextToken());
		
		
		for(int tc=1;tc<=T;tc++) {
			st=new StringTokenizer(br.readLine());
			N=Integer.parseInt(st.nextToken());
			M=Integer.parseInt(st.nextToken());
			
			map=new char[N][M];
			dist=new int[N][M];
			list=new ArrayList<>();
			for(int i=0;i<N;i++) {
				Arrays.fill(dist[i], -1); //초기화 
			}
			
			ans= 0;
			Queue<p> q= new ArrayDeque<>();
			for(int i=0;i<N;i++) {
				st=new StringTokenizer(br.readLine());
				String s = st.nextToken();
				for(int j=0;j<M;j++) {
					map[i][j]=s.charAt(j);
					if(map[i][j]=='W') {
						q.add(new p(i, j)); //물의 위치 추가 
						dist[i][j]=0;
					}
				}
			}
			while(!q.isEmpty()) {
				p p=q.poll();
				int x= p.x;
				int y= p.y;
				for(int dir=0;dir<4;dir++) {
					int nx=x+dx[dir];
					int ny=y+dy[dir];
					if(nx<0||nx>=N||ny<0||ny>=M) continue;
					if(map[nx][ny]=='L' && (dist[nx][ny]==-1 || dist[nx][ny]!=-1 && dist[nx][ny]>dist[x][y]+1)) {
						//땅에 방문하지 않았거나 땅과 다른 물 사이의 기존 거리보다 현재 물과 땅의 거리가 더 가까운 경우 갱신 
						dist[nx][ny]=dist[x][y]+1;
						q.add(new p(nx, ny));
					}
				}
			}
			for(int i=0;i<N;i++) {
				for(int j=0;j<M;j++) {
					if(dist[i][j]==-1) continue;
					ans+=dist[i][j]; //-1이 아닌 값만 더해줌 
				}
			}
			System.out.println("#"+tc+" "+ans);
		}
		
	}

}
