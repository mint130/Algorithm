import java.util.Scanner;

public class Main {

	static int N, K, belt[], res;
	static boolean robot[];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N =sc.nextInt();
		K=sc.nextInt();
		
		belt = new int[2*N];
		
		robot = new boolean[N]; //로봇이 현재 있는 곳 
		for(int i=0;i<2*N;i++) {
			belt[i]=sc.nextInt();
		}
		res=0; //단계 
		
		while(K>0) {
			//회전
			int tmp=belt[2*N-1];
			for(int i=2*N-1;i>0;i--) {
				belt[i]=belt[i-1];
				
			}
			belt[0]=tmp;
			for(int i=N-1;i>0;i--) {
				robot[i]=robot[i-1];
			}
			robot[0]=false;
			robot[N-1]=false;
			//이동 
			for(int i=N-1;i>0;i--) {
				if(robot[i-1]&& belt[i]>=1 && !robot[i]) {
					robot[i-1]=false;
					robot[i]=true;
					//옮김 
					belt[i]--;
					//내구도 감소 
					if(belt[i]==0) {
						K--;
					}
					
					
				}
			}
			if(belt[0]>0) {
				robot[0]=true;
				belt[0]--;
				
				if(belt[0]==0) {
					K--;
				}
			}
			res++;
		}
		System.out.println(res);
	}

}
