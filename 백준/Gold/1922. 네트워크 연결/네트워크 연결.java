import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {

	static int N, M;
	static int p[];
	static class Edge implements Comparable<Edge>{
		int st, en, w;
		public Edge(int st, int en, int w) {
			this.st=st;
			this.en=en;
			this.w=w;
		}
		@Override
		public int compareTo(Edge o) {
			return Integer.compare(this.w, o.w);
		}
	}
	static int find(int a) {
		if(p[a]==-1) return a;
		return p[a]=find(p[a]);
	}
	static boolean union(int a, int b) {
		a=find(a);
		b=find(b);
		if(a==b) return false;
		p[a]=b;
		return true;
	}
	public static void main(String[] args) {
		// 크루스칼
		Scanner sc = new Scanner(System.in);
		N=sc.nextInt();
		M=sc.nextInt();
		p=new int[N+1];
		ArrayList<Edge> list=new ArrayList<>();
		Arrays.fill(p, -1);
		//모든 컴퓨터를 연결하는데 드는 최소 비용 -> 크루스칼  
		for(int i=0;i<M;i++) {
			list.add(new Edge(sc.nextInt(), sc.nextInt(), sc.nextInt()));
		}
		Collections.sort(list);
		int cnt=0;
		int sum=0;
		for(Edge e:list) {
			if(union(e.st, e.en)) {
				cnt++;
				sum+=e.w;
			}
			if(cnt==N-1) {
				System.out.println(sum);
				break;
			}
		}

	}

}
