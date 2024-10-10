import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int n, t, stx, sty, conx[], cony[], enx, eny;
	static boolean visit[];
	static class point{
		int x, y;

		public point(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}
		
	}
	static void BFS() {
		Queue<point> q = new ArrayDeque<>();
		q.add(new point(stx, sty));
		while(!q.isEmpty()) {
			point p = q.poll();
			int x = p.x;
			int y = p.y;
			if(Math.abs(x-enx)+Math.abs(y-eny)<=1000) {
				//목적지에 도달 
				System.out.println("happy");
				return;
			}
			for(int i=0;i<n;i++) {
				if(!visit[i]) {
					//방문한 적 없음 
					if(Math.abs(x-conx[i])+Math.abs(y-cony[i])<=1000) {
						visit[i]=true;
						//i번째 편의점 방문 
						q.add(new point(conx[i], cony[i]));
					}
				}
			}
		}
		
		System.out.println("sad");
		
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		t = Integer.parseInt(st.nextToken());
		for(int tc=1;tc<=t;tc++) {
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			
			stx = Integer.parseInt(st.nextToken());
			sty = Integer.parseInt(st.nextToken());
			
			conx=new int[n];
			cony=new int[n];
			visit=new boolean[n];
			for(int i=0;i<n;i++) {
				st = new StringTokenizer(br.readLine());
				conx[i]=Integer.parseInt(st.nextToken());
				cony[i]=Integer.parseInt(st.nextToken());
			}
			
			st = new StringTokenizer(br.readLine());
			enx=Integer.parseInt(st.nextToken());
			eny=Integer.parseInt(st.nextToken());
			
			BFS();
		}

	}

}
