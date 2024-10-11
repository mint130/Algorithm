import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static String t, p;
	static int pi[]; 
	static int cnt = 0; //몇번 나타나는지 
 
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		t=br.readLine();
		p=br.readLine();
		pi=new int[p.length()];
		//문자열 p 전처리 
		func();
		//System.out.println(Arrays.toString(pi));
		int i=0;
		int j=0;
		StringBuilder sb=new StringBuilder();
		while(i<t.length()){
			if(t.charAt(i)==p.charAt(j)) {
				//문자 일치 
				if(j==p.length()-1) {
					//끝까지 일치 
					cnt++;
					sb.append((i-j+1)+" ");
					j=pi[j]; //왜지 
				}
				else {
					j++;
				}
				i++;
			}
			else {
				if(j==0) {
					i++;
				}
				else {
					j=pi[j-1];
				}
				
			}
			
		}
		System.out.println(cnt);
		System.out.println(sb);
	}
	static void func() {
		//t를 가지고 전처리 
		pi[0]=0;
		int i = 1, j = 0;
		//A 0 -> 0
		//AB 1 -> 0
	 	//ABC 2 -> 0
		//ABCD 3 -> 0
		//ABCDA 4 -> 1
		//ABCDAB 5 -> 2 
		//ABCDABD 6 -> 0
		while(i<p.length()) {
			if(p.charAt(i)==p.charAt(j)) {
				pi[i]=j+1;
				i++;
				j++;
			}
			else {
				if(j==0) {
					pi[i]=0;
					i++;
				}
				else {
					j=pi[j-1];
				}
			}
			
		}
		
	}

}
