import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	private static class Node implements Comparable<Node> {
		int to, cost;
		
		Node(int to, int cost) {
			this.to = to;
			this.cost = cost;
		}
		
		@Override
		public int compareTo(Node o) {
			return Integer.compare(this.cost, o.cost);
		}
	}
	
	private static ArrayList<Node>[] Nodes;

	public static void main(String[] args) throws Exception {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    StringBuilder sb = new StringBuilder();
	    
	    while (true) {
	        StringTokenizer st = new StringTokenizer(br.readLine());
	        int numOfHouses = Integer.parseInt(st.nextToken());
	        int numOfRoads = Integer.parseInt(st.nextToken());
	        
	        if (numOfHouses == 0 && numOfRoads == 0) break;
	        
	        Nodes = new ArrayList[numOfHouses];
	        for (int i = 0; i < numOfHouses; i++) {
	            Nodes[i] = new ArrayList<>();
	        }
	        
	        int totalCost = 0;
	        // numOfRoads만큼만 반복
	        for (int i = 0; i < numOfRoads; i++) {
	            st = new StringTokenizer(br.readLine());
	            int from = Integer.parseInt(st.nextToken());
	            int to = Integer.parseInt(st.nextToken());
	            int cost = Integer.parseInt(st.nextToken());
	            
	            Nodes[from].add(new Node(to, cost));
	            Nodes[to].add(new Node(from, cost));
	            totalCost += cost;
	        }
	        
	        int minCost = prim(0, numOfHouses, numOfRoads);
	        sb.append(totalCost - minCost).append('\n');
	    }
	    
	    System.out.print(sb);
	}
	
//	public static void main(String[] args) throws Exception {
//		
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringTokenizer st = new StringTokenizer(br.readLine());
//		int numOfHouses = Integer.parseInt(st.nextToken()), numOfRoads = Integer.parseInt(st.nextToken());
//		
//		Nodes = new ArrayList[numOfHouses];
//		for (int i = 0; i < numOfHouses; i++)	Nodes[i] = new ArrayList<>();
//		
//		int totalCost = 0;
//		while (true) {
//			st = new StringTokenizer(br.readLine());
//			int from = Integer.parseInt(st.nextToken()), to = Integer.parseInt(st.nextToken());
//			
//			if (from == 0 && to == 0)	break;
//			
//			int cost = Integer.parseInt(st.nextToken());
//			Nodes[from].add(new Node(to, cost));
//			Nodes[to].add(new Node(from, cost));
//			totalCost += cost;
//		}
//		
//		int minCost = prim(0, numOfHouses, numOfRoads);
//		int answer = totalCost - minCost;
//		System.out.println(answer);
////		br.close();
//	}
	
	
	private static int prim(int startNode, int numOfHouses, int numOfRoads) {
		boolean[] mst = new boolean[numOfHouses];
		PriorityQueue<Node> pq = new PriorityQueue<>();
		mst[startNode] = true;

		// 시작 노드와 연결된 인접 노드 정보들 pq에 등록
		for (Node otherNode : Nodes[startNode]) {
			pq.add(new Node(otherNode.to, otherNode.cost));
		}
		
		int answer = 0, vertexCount = 1;
		while (!pq.isEmpty()) {
			Node currentNode = pq.poll();
			
			if (mst[currentNode.to])	continue;
			
			mst[currentNode.to] = true;
			answer += currentNode.cost;
			vertexCount++;
			
			if (vertexCount == numOfHouses) break;
			
			for (Node otherNode : Nodes[currentNode.to]) {
				if (mst[otherNode.to])	continue;
				pq.add(new Node(otherNode.to, otherNode.cost));
			}
		}
		
		return answer;
	}
}
