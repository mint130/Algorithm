//오목 

import java.util.Scanner;


public class Main {

	static int map[][]=new int[19][19];
	//static boolean visit[][]=new boolean[19][19];
	static int dx[]= {1, 0, 1, 1};
	static int dy[]= {0, 1, 1, -1};
	static int a, b, c, d;
	static int func(int x, int y, int num, int dir) {
		//x, y에서 시작 
		//System.out.println("시작 "+x+" "+y+" 방향 "+dir);
		
		int cnt =1;
		int nx=x+dx[dir];
		int ny=y+dy[dir];
		while(nx<19 && nx>=0 && ny<19 && ny>=0 && map[nx][ny]==num) {
			cnt++;
			nx+=dx[dir];
			ny+=dy[dir];
		}
		//System.out.println("갯수 "+cnt);
		if(cnt==5) {
			if(dir==0 && x>0 && map[x-1][y]==num) return 0;
			if(dir==1 && y>0 && map[x][y-1]==num) return 0;
			if(dir==2 && y>0 && x>0 && map[x-1][y-1]==num) return 0;
			if(dir==3 && y<=19 && x>0 && map[x-1][y+1]==num) return 0;
			return num;
		}
		return 0;
		
		
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for(int i=0;i<19;i++) {
			for(int j=0;j<19;j++) {
				map[i][j]=sc.nextInt();
			}
		}
		//검은색 1 
		//흰색 2 
		int flag=0;
		for(int i=0;i<19;i++) {
			for(int j=0;j<19;j++) {
				if(map[i][j]==1) {
					//검은색 
					a=0; b=0; c=0; d=0;
					if(i<15) a=func(i ,j, 1, 0); //세로 
					if(j<15) b=func(i, j, 1, 1); //가로 
					if(i<15 && j<15) c=func(i, j, 1, 2); //대각선 (오른쪽 아래로)
					if(i<15 && j>=4) d=func(i, j, 1, 3); //대각선 (왼쪽 아래로) 
					if(d==1) {
						System.out.println(1);
						System.out.println((i+1+4)+" "+(j+1-4));
						return;
					}
					if(a==1||b==1||c==1) {
						System.out.println(1);
						System.out.println((i+1)+" "+(j+1));
						return;
					}
			
					//5개 연속->1 
					//5개보다 많아지면 0
				}
				if(map[i][j]==2){
					//흰색 
					a=0; b=0; c=0; d=0;
					if(i<15) a=func(i, j, 2, 0); //세로 
					if(j<15) b=func(i, j, 2 ,1); //가로 
					if(i<15 && j<15) c=func(i, j, 2, 2); //대각선 
					if(i<15 && j>=4) d=func(i, j, 2, 3); //대각선 왼쪽 아래  
					if(d==2) {
						System.out.println(2);
						System.out.println((i+1+4)+" "+(j+1-4));
						return;
					}
					if(a==2||b==2||c==2||d==2) {
						System.out.println(2);
						System.out.println((i+1)+" "+(j+1));
						return;
					}
					
				}
			}
		}
		System.out.println(0);
		return;
	}

}
