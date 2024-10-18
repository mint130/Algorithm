import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N, egg[][], res;
    static void dfs(int cur, int cnt) {
        //cur은 현재 들고 있는 계란 번호 
        //cnt는 깬 계란 갯수 
        if(cur==N) {
            //가장 오른쪽의 계란을 들고 있으면 끝
        	res=Math.max(cnt, res);
            return;
        }
    
        if(egg[cur][0]<=0 || cnt==N-1) {
        	dfs(cur+1, cnt); //현재 든 계란이 깨졌거나 나머지 계단이 모두 깨짐 
        	return;
        }
        for(int i=0;i<N;i++) {
            if(i==cur) continue;
            if(egg[i][0]<=0) continue;
            
            //i번째 계란은 아직 안깨짐
            
            egg[cur][0]-=egg[i][1];
            egg[i][0]-=egg[cur][1];
            //각각 내구도 감소 

            int c = cnt;
            if(egg[cur][0]<=0) c++;
            if(egg[i][0]<=0) c++;
            dfs(cur+1, c);

            egg[cur][0]+=egg[i][1];
            egg[i][0]+=egg[cur][1]; //복구 

        }
        
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N=Integer.parseInt(st.nextToken());
        egg=new int[N][2]; //i번째 계란 0 내구도, 1 무게
        res=0;
        for(int i=0;i<N;i++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken()); //내구도 
            int w = Integer.parseInt(st.nextToken()); //무게 
            egg[i][0]=s;
            egg[i][1]=w;
        }
        dfs(0, 0);
        System.out.println(res);
        
        
        

    }

}