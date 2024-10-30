import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int N, K, L, sec;
	static int board[][];
	static int dx[]= {0, 1, 0, -1};
	static int dy[]= {1, 0, -1, 0}; //우 하 좌 상
	static int snake[][]; //뱀의 움직임
	static int d[]; //왼쪽은 -1 오른쪽은 +1
	public static class point {
		int headX, headY;
		int dir;
		public point(int headX, int headY, int dir) {
			super();
			this.headX = headX;
			this.headY = headY;
			this.dir = dir;
		}
		
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N=Integer.parseInt(st.nextToken());
		board = new int[N][N];
		snake = new int[N][N];
		d = new int[10001];
		st = new StringTokenizer(br.readLine());
		K=Integer.parseInt(st.nextToken());
		for(int i=0;i<K;i++) {
			st=new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			board[x-1][y-1]=1;
		}
		
		st =new StringTokenizer(br.readLine());
		L=Integer.parseInt(st.nextToken());
		for(int i=0;i<L;i++) {
			st=new StringTokenizer(br.readLine());
			int x=Integer.parseInt(st.nextToken());
			String str=st.nextToken();
			if(str.equals("L")) d[x]=-1;
			else d[x]=1;
		}
		
		
		//board가 1이면 사과
		//snake가 1이면 뱀이 위치해있음 
		Queue<point> q =new ArrayDeque<>();
		List<int[]> list= new ArrayList<>();
		q.add(new point(0, 0, 0));
		list.add(new int[] {0, 0});
		snake[0][0]=1;
		while(!q.isEmpty()) {
			//System.out.println(sec+" ");
			//for(int i=0;i<N;i++) System.out.println(Arrays.toString(snake[i]));
			
			point p=q.poll();
			
			int hx=p.headX;
			int hy=p.headY;
			int dir=p.dir;
				
			//dir은 다음 방향으로 갱신
			dir=(dir+d[sec])%4;
			if(dir==-1) dir=3;
			d[sec]=dir; //바꾼 방향 저장 
			
			int nx=hx+dx[dir];
			int ny=hy+dy[dir];
			
			//nx, ny는 뱀의 머리가 도달하는 위치
			if(nx<0||nx>=N||ny<0||ny>=N) {
				//만약 벽에 도달하면 끝
				System.out.println(sec+1);
				return;	
			}
			if(snake[nx][ny]==1) {
				//자기자신에 닿으면 끝
				System.out.println(sec+1);
				return;
				
			}
			
			if(board[nx][ny]==1) {
				//사과가 있다 
				//헤드가 사과 위치로 감 
				board[nx][ny]=0;
				//뱀의 머리 위치 갱신 
				list.add(0, new int[] {nx, ny}); //머리 넣음
				snake[nx][ny]=1;
				q.add(new point(nx, ny, dir));
			}	
			else {
				//사과가 없다
				//헤드랑 꼬리 다 이동
				//뱀의 머리 꼬리 위치 갱신 
				for(int i=0;i<list.size();i++) {
					int nxtx=list.get(i)[0];
					int nxty=list.get(i)[1];
					snake[nxtx][nxty]=0;
					int nxt=d[sec-i];
					list.get(i)[0]=nxtx+dx[nxt];
					list.get(i)[1]=nxty+dy[nxt];
					snake[list.get(i)[0]][list.get(i)[1]]=1;
				}
				q.add(new point(list.get(0)[0], list.get(0)[1], dir));
			}
			sec++;
	
		}

	}

}
