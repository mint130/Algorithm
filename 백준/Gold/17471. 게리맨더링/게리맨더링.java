import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int N, city[], ans;
	static List<Integer> list[];
	static boolean isSelected[];
	static boolean bfs(List<Integer> temp) {
		//구역이 인접한지 확인 
		int cnt=1;
		Queue<Integer> q =new ArrayDeque<>();
		q.add(temp.get(0));
		boolean visited[]=new boolean[N];
		visited[temp.get(0)]=true;
		//방문 
		//queue에 있는걸로 bfs
		while(!q.isEmpty()) {
			int cur = q.poll();
			
			for(int nxt:list[cur]) {
				if(!visited[nxt] && temp.contains(nxt)) {
					//아직 방문하지 않았고 temp에 포함되어있음 
					visited[nxt]=true;
					q.add(nxt);
					cnt++;
				}
			}
		}
		if(cnt==temp.size()) return true;
		else return false;
		
	}
	static void dfs(int cnt) {
		if(cnt==N) {
			List<Integer> a= new ArrayList<>();
			List<Integer> b= new ArrayList<>();
			//a구역, b구역에 지역구 번호 넣음 
			for(int i=0;i<N;i++) {
				if(isSelected[i]) a.add(i);
				else b.add(i);
			}
			if(a.size()>0 && b.size()>0) {
				//적어도 한 구역이 존재해야함  
				if(bfs(a) && bfs(b)) {
					//두 구역의 인구차 구하기
					int pA=0;
					int pB=0;
					for(int i:a) {
						pA+=city[i];
					}
					for(int i:b) {
						pB+=city[i];
					}
					ans=Math.min(ans, Math.abs(pA-pB));
				}
				
			}
			return;
		}
		//부분집합
		isSelected[cnt]=true;
		dfs(cnt+1);
		isSelected[cnt]=false;
		dfs(cnt+1);
	}
	
	public static void main(String[] args) throws IOException {
		//선거구는 구열 포함
		//한 선거구에 포함되어 있으면 모두 연결 
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N= Integer.parseInt(st.nextToken());
		ans=Integer.MAX_VALUE;
		city =new int[N]; //인구수 저장
		isSelected = new boolean[N];
		st =new StringTokenizer(br.readLine());
		for(int i=0;i<N;i++) {
			city[i]=Integer.parseInt(st.nextToken());
		}
		
		//1부터 i구역까지 인접한 구역 번호 저장 
		list = new ArrayList[N];
		
		for(int i=0;i<N;i++) {
			list[i]=new ArrayList<Integer>();
		}
		//list에 인접한 구역 저장 
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			int M = Integer.parseInt(st.nextToken());
			for(int j=0;j<M;j++) {
				list[i].add(Integer.parseInt(st.nextToken())-1);
			}
		}
		dfs(0);
		System.out.println(ans==Integer.MAX_VALUE? -1: ans);
	
	
	}
	

}
