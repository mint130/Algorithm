import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

    static int T, N, dist[][], ans;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        T=Integer.parseInt(st.nextToken());
        for(int tc=1;tc<=T;tc++) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            dist = new int[N+1][N+1];
            ans = Integer.MAX_VALUE;
            for(int i=1;i<=N;i++) {
                for(int j=1;j<=N;j++) {
                    dist[i][j]=Integer.parseInt(st.nextToken());
                    if(dist[i][j]==0) dist[i][j]=987654321;
                    if(i==j) dist[i][j]=0;
                }
            }
            for(int k=1;k<=N;k++) {
                for(int i=1;i<=N;i++) {
                    for(int j=1;j<=N;j++) {
                        if(i==j) continue;
                        if(dist[i][k]+dist[k][j]<dist[i][j]) dist[i][j]=dist[i][k]+dist[k][j];
                        
                    }
                }
            }
            for(int i=1;i<=N;i++) {
                int cnt = 0;
                for(int j=1;j<=N;j++) {
                    //cc값
                    cnt+=dist[i][j];
                }
                ans=Math.min(ans, cnt);
            }
            System.out.println("#"+tc+" "+ans);
            
            
        }

    }

}