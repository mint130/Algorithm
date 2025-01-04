import java.util.*;
class Solution {
    //다익스트라
    int dist[];

    public int[] solution(int n, int[][] roads, int[] sources, int destination) {
        int[] answer = new int[sources.length];
        ArrayList<Integer> arr[];
        arr=new ArrayList[n+1];
        dist=new int[n+1];
        for(int i=1;i<=n;i++){
            arr[i]=new ArrayList<>();
        }
        Arrays.fill(dist, 987654321);
        dist[destination]=0;
        
        int m=roads.length;
        for(int i=0;i<m;i++){
            int st = roads[i][0];
            int en = roads[i][1];
            arr[st].add(en);
            arr[en].add(st);
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        pq.add(destination);
        while(!pq.isEmpty()){
            int cur = pq.poll();
            for(int nxt:arr[cur]){
                if(dist[nxt]>dist[cur]+1){
                    dist[nxt]=dist[cur]+1;
                    pq.add(nxt);
                }
            }
            
        }
        for(int i=0;i<sources.length;i++){
            answer[i]=dist[sources[i]];
            if(answer[i]==987654321) answer[i]=-1;
        }
        return answer;
    }
}