import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main{
    static int arr[]=new int[26];
	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st= new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken());
        for(int i=0;i<n;i++) {
        	String s=br.readLine();
        	arr[s.charAt(0)-'a']++;
        }
        boolean flag = false;
        String ans="PREDAJA";
        for(int i=0;i<26;i++) {
        	if(arr[i]>=5) {
        		flag=true;
        		System.out.print((char)(i+'a'));
        	}
        }
        if(!flag) System.out.println(ans);   
	}
    
    
}