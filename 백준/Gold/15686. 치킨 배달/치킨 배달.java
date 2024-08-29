import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	static int N, M; //M은 고를 수 있는 치킨 집 
	static int map[][]; //지도  
	static int ans = 987654321;
	static class Point{
		int x, y;
		public Point(int x, int y) {
			this.x=x;
			this.y=y;
		}
	}
	static ArrayList<Point> h; //집의 좌표 저장 
	static ArrayList<Point> c; //치킨 좌표 저장 

	
	static boolean check[];
	static int dist(int x1, int y1, int x2, int y2) {
		return Math.abs(x1-x2)+Math.abs(y1-y2);
	}
	static int sum() {
		int sum=0; //집의 좌표를 돌며 check가 true인 치킨집과의 거리 중 가장 작은 거리의 합 저장 
		for(int i=0;i<h.size();i++) {
			int len=987654321;
			for(int j=0;j<c.size();j++) {
				if(check[j]) {
					//선택된 치킨집 중에서 i번째 집과 가장 가까운 거리 len에 저
					len=Math.min(len, dist(h.get(i).x, h.get(i).y, c.get(j).x, c.get(j).y));
				}
			}
			sum+=len;
		}
		return sum;		
	}
	static void dfs(int depth, int idx) {
		//치킨집 중 M개 고름(조합)
		if(depth==M) {
			//치킨집 다 고름 
			ans=Math.min(ans, sum());
			return;
		}
		for(int i=idx;i<c.size();i++) {
			if(!check[i]) {
				check[i]=true;
				dfs(depth+1, i+1);
				check[i]=false;
			}
		}
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N=sc.nextInt();
		M=sc.nextInt();
		map=new int[N][N];
		h=new ArrayList<>();
		c=new ArrayList<>();
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				map[i][j]=sc.nextInt();
				if(map[i][j]==1) h.add(new Point(i, j));
				if(map[i][j]==2) c.add(new Point(i, j));
			}
		}
		check=new boolean[c.size()]; //치킨집의 갯수만큼 check 배열 생성 
		
		dfs(0, 0);
		System.out.println(ans);
	}

}
