import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.AttributedCharacterIterator;
import java.util.StringTokenizer;

public class Solution {
	

	static int answer1=0; //규영 이김
	static int answer2=0; //규영 짐
	static boolean num[]=new boolean[19]; //규영이가 가지면 1, 인영이가 가지면 0
	static int a[]=new int[9]; //규영이가 내는 카드 순서
	static boolean isSelected[] = new boolean[19]; //i가 사용 되었는지
	static void dfs(int idx, int scoreA, int scoreB) {
		//idx는 몇번째 카드 냈는지
		//scoreA는 규영 점수 scoreB는 인영 점수
		if(idx==9) {
			if(scoreA>scoreB) answer1++;
			else if(scoreB>scoreA) answer2++;
			return;
		}
		int k=a[idx]; //규영이 낸 카드 점수
		for(int i=1;i<=18;i++) {
			if(!num[i] && !isSelected[i]) {
				isSelected[i]=true;
				if(k>i) dfs(idx+1, scoreA+i+k, scoreB); // 규영 이김
				else dfs(idx+1, scoreA, scoreB+i+k); // 규영 짐
				isSelected[i]=false;
			}
		}
		
	}
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st= new StringTokenizer(br.readLine());
		int T =Integer.parseInt(st.nextToken());
		for(int tc = 1;tc<=T;tc++) {
			st=new StringTokenizer(br.readLine()," ");
			for(int i=0;i<9;i++) {
				a[i]=Integer.parseInt(st.nextToken()); //i번째 낼 숫자
				num[a[i]]=true; //num이 규영이가 가진 숫자인지(1) 인영이가 가진 숫자인지(0)
			}
			dfs(0, 0, 0);
			System.out.println("#"+tc+" "+answer1+" "+answer2);
			answer1=0; answer2=0;
			for(int i=1;i<=18;i++) {
				isSelected[i]=false;
				num[i]=false;
			}
		}
		
	}

}
