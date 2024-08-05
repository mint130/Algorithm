import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.TreeSet;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int [] arr= new int [n];
		TreeSet<Integer> treeSet = new TreeSet<>();
		long answer = 0;
		for(int i=0;i<n;i++) {
			arr[i]=Integer.parseInt(br.readLine()); //예상 등수
			treeSet.add(i+1); //1부터 n까지의 숫자(실제 등수) set에 집어 넣음
		}
		Arrays.sort(arr); //예상 등수 정렬
		
		for(int i=0;i<n;i++) {
			if(treeSet.contains(arr[i])) {
				//실제 등수 선점 가능
				treeSet.remove(arr[i]);
				//set에서 삭제
			}
			else {
				//arr[i]의 값이 set에 존재하지 않는다 = arr[i]의 등수를 누군가 선점했음
				//불만도 존재, set의 가장 처음(작은 수)값과 현재 예상 등수의 차가 가장 적음
				answer += Math.abs(arr[i]-treeSet.pollFirst());
			}
		}
		System.out.println(answer);
		
		
	}

}
