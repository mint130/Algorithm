import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	static int N, M;
	static ArrayList<Integer> list[]; //친구 정보 저장
	static boolean visit[];
	static boolean flag;
	static void dfs(int depth, int cur) {
		if(depth==4) {
			flag=true;
			//관계 있음
			return;
		}
		for(int nxt:list[cur]) {
			if(!visit[nxt]) {
				visit[nxt]=true;
				dfs(depth+1, nxt);
				visit[nxt]=false;
			}
		}
		
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N=sc.nextInt(); 
		M=sc.nextInt();
		list = new ArrayList[N];
		
		for(int i=0;i<N;i++) {
			list[i]=new ArrayList<>();
		}
		for(int i=0;i<M;i++) {
			int a, b;
			a=sc.nextInt();
			b=sc.nextInt();
			list[a].add(b);
			list[b].add(a);
		}
		for(int i=0;i<N;i++) {
			visit=new boolean[N];
			visit[i]=true;
			dfs(0, i);
			if(flag) {
				System.out.println(1);
				return;
			}
		}
		System.out.println(0);

	}

}
