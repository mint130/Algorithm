import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class Solution {
	

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st= new StringTokenizer(br.readLine());
		
		int T = Integer.parseInt(st.nextToken());
		for(int tc=1;tc<=T;tc++) {
			st= new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			
			int [][] arr = new int[N][N];
			int cnt = 1;
			int n = N-1;
			int k = 0;
			if(N==1) arr[0][0]=1;
			else {
				while(cnt<=N*N) {
					int col=k;
					int row=k;
					//시작 좌표
					//n만큼 왼->오
					for(int i=0;i<n;i++) {
						if(arr[row][col+i]!=0) break;
						arr[row][col+i]=cnt;
						//System.out.println("왼 오 좌표 x "+row+" 좌표 y "+(col+i));
						cnt++;
					}
					
				
					
					
					//n만큼 위->아래
					col=k+n;
					for(int i=0;i<n;i++) {
						if(arr[row+i][col]!=0) break;
						arr[row+i][col]=cnt;
						//System.out.println("위 아래 좌표 x "+(row +i)+" 좌표 y "+col);
						cnt++;
					}
					
					
					
					//n만큼 오->왼
					row=k+n;
					for(int i=0;i<n;i++) {
						if(arr[row][col-i]!=0) break;
						arr[row][col-i]=cnt;
						//System.out.println("오 왼 좌표 x "+(row)+" 좌표 y "+(col-i));
						cnt++;
					}
					
					//n만큼 아래->위
					col=k;
					for(int i=0;i<n;i++) {
						if(arr[row-i][col]!=0) break;
						arr[row-i][col]=cnt;
						//System.out.println("아래 위 좌표 x "+(row-i)+" 좌표 y "+col);
						cnt++;
					}
					
					
					row=k;
					n=n-2;
					if(n==0) n=1;
					k++;
					
				}
				
			}
			
			
			System.out.println("#"+tc);
			for(int i=0;i<N;i++) {
				for(int j=0;j<N;j++) {
					System.out.print(arr[i][j]+" ");
				}
				System.out.println();
			}
		}
		
	}

}
