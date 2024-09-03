import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

	static int V, E, start, dist[];
	static boolean visit[];
	static class Node{
		int num;
		int weight;
		public Node(int num, int weight) {
			super();
			this.num = num;
			this.weight = weight;
		}
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		V=sc.nextInt();
		E=sc.nextInt();
		final int INF= Integer.MAX_VALUE;
		start=sc.nextInt();
		ArrayList<Node> list[]=new ArrayList[V+1]; //이어진 정점
		for(int i=1;i<=V;i++) {
			list[i]=new ArrayList<>();
		}
		dist=new int[V+1]; //시작 정점에서 i까지의 길이 
		visit=new boolean[V+1]; //방문 했는지 
		Arrays.fill(dist, INF);
		PriorityQueue<Node> pq=new PriorityQueue<>(new Comparator<Node>() {
			@Override
			public int compare(Node o1, Node o2) {
				return Integer.compare(o1.weight, o2.weight);
			}
		});
		dist[start]=0;
		pq.add(new Node(start, dist[start]));
		
		
		
		for(int i=0;i<E;i++) {
			int u, v, w;
			u=sc.nextInt();
			v=sc.nextInt();
			w=sc.nextInt();
			list[u].add(new Node(v, w));
		}
		
		while(!pq.isEmpty()) {
			Node n=pq.poll();
			int cur=n.num;
			int w=n.weight;

			if(visit[cur]) continue;
			visit[cur]=true;
			for(Node nxt:list[cur]) {
				if(!visit[nxt.num] && dist[nxt.num]>nxt.weight+dist[cur]) {
					dist[nxt.num]=nxt.weight+dist[cur];
					pq.add(new Node(nxt.num, dist[nxt.num]));
				}
			}
		}
		for(int i=1;i<=V;i++) {
			if(dist[i]==INF) System.out.println("INF");
			else System.out.println(dist[i]);
		}
	}

}
