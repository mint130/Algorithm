import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.AttributedCharacterIterator;
import java.util.StringTokenizer;

public class Solution {
	
	static int arr[]=new int[6]; //입력 받음
	static int res[]=new int[6]; //완성되는 배열
	static boolean isSelected[]=new boolean[6]; //isSelected[idx] => arr[idx]번째가 쓰였는지
	static boolean flag=false;
	static boolean isR(int st) {
		//run인지(연속)
		return res[st]+1==res[st+1]&&res[st+1]+1==res[st+2];
	}
	static boolean isT(int st) {
		//triplet인지 (동일한 번호)
		return res[st]==res[st+1]&&res[st+1]==res[st+2];
	}
	
	static void dfs(int idx) {
		if(idx==6) {
			//3개씩 잘라서 run, triplet인지 검사
			boolean lr = isR(0); //앞이 run
			boolean rr = isR(3); //뒤가 run
			boolean lt = isT(0); //앞이 triplet
			boolean rt = isT(3); //뒤가 triplet
			
			if((lr && rr)||(lr && rt)||(lt && rr)||(lt && rt)) {
				flag=true;
			}
			//하나라도 베이비진인 경우 true, return
			//아닌 경우 false
			return;
		}
		for(int i=0;i<6;i++) {
			if(!isSelected[i]) {
				res[idx]=arr[i];
				isSelected[i]=true;
				dfs(idx+1);
				isSelected[i]=false;
			}
		}
	}
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int tc = 1;tc<=T;tc++) {
			String s=br.readLine();
			for(int i=0;i<s.length();i++) {
				arr[i]=s.charAt(i)-'0';
			}
			dfs(0);
			System.out.println("#"+tc+" "+flag);
			flag = false;
			for(int i=0;i<6;i++) {
				isSelected[i]=false;
			}
		}
		
	}

}
