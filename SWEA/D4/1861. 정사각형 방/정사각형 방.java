import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {
	static int T;
	static int N;
	static int board[][];
	static int dx[]={1, 0, -1, 0};
	static int dy[]= {0, 1, 0, -1};
	static int move =0; //최대 몇개의 방 움직일 수 있는지 
	static int start; //시작 지점 
	static class point {
		int x, y;
		public point(int x, int y) {
			this.x=x;
			this.y=y;
		}
	}
	static void bfs(int r, int c) {
		//한번에 몇칸 이동할 수 있는지
		boolean visit[][]=new boolean[N][N];
		visit[r][c]=true;
		Queue<point> q= new LinkedList<>();
		q.add(new point(r, c));
		int cnt = 0; //움직이는 횟
		int st=board[r][c]; //시작 지점 
		while(!q.isEmpty()) {
			int x=q.peek().x;
			int y=q.peek().y;
			q.poll();
			cnt++;
			int num = board[x][y];
			for(int i=0;i<4;i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
				if(board[nx][ny]==num+1 && !visit[nx][ny]) {
					visit[nx][ny]=true;
					q.add(new point(nx, ny));
				}
			}
		}

		if(move<=cnt) {
			if(move==cnt) {
				if(start>st) start=st;
				return;
			}
			move=cnt;
			start=st;
		}
		
	}
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st =new StringTokenizer(br.readLine());
		T=Integer.parseInt(st.nextToken());
		for(int tc=1;tc<=T;tc++) {
			st =new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			board = new int[N][N];
			
			move=0;
			start=N*N;
			for(int i=0;i<N;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<N;j++) {
					board[i][j] =Integer.parseInt(st.nextToken());					
				}
			}
			for(int i=0;i<N;i++) {
				for(int j=0;j<N;j++) {
					bfs(i, j);
				}
			}
			System.out.println("#"+tc+" "+start+" "+move);
		}
	}

}
