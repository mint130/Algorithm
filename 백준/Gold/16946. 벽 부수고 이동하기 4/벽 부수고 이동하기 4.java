import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
	private static int N, M;
	private static int[][] Map;
	private static HashMap<Integer, Integer> EmptyAreas = new HashMap<>();

	private static final int DIRECTION_COUNT = 4;
	private static final int[] ROW_DIRS = {-1, 1, 0, 0};
	private static final int[] COL_DIRS = {0, 0, -1, 1};
	
	public static void main(String[] args) throws Exception {

		// 1. 입력 받기
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		Map = new int[N][M];
		
		for (int i = 0; i < N; i++) {
			String row = br.readLine();
			for (int j = 0; j < M; j++)	Map[i][j] = row.charAt(j) - '0';
		}
		
		// 2. BFS를 통해 빈 공간 파악 (각각의 빈 공간에 대해 ID와 개수를 Key, Value로 관리)
		// 벽이 1이므로, 2번부터 id 값 설정
		int id = 2;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				if (Map[r][c] != 0)	continue;

				int count = bfs(r, c, id) % 10;
				EmptyAreas.put(id++, count);
			}
		}
		
		// 3. 벽을 기점으로 상하좌우를 탐색해, 벽이 아니고 중복된 id 공간을 고르지 않도록 세팅
		StringBuilder answer = new StringBuilder();
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				// 벽이 아닐 경우에는 0으로 세팅
				if (Map[r][c] != 1) {
					answer.append(0);
				} 
				
				// 벽일 경우에는 상하좌우 살피며 중복 없이 개수 체크
				else {
					HashSet<Integer> selectedIds = new HashSet<>();
					int result = 0;

					for (int i = 0; i < DIRECTION_COUNT; i++) {
						int nextRow = r + ROW_DIRS[i];
						int nextCol = c + COL_DIRS[i];
						
						// 맵 밖이거나 벽일 경우
						if (nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= M || Map[nextRow][nextCol] == 1)
							continue;
						
						int targetId = Map[nextRow][nextCol];
						
						// 이미 선택한 빈 공간 영역일 경우엔 Skip
						if (selectedIds.contains(targetId))
							continue;
						
						result += EmptyAreas.get(targetId);
						selectedIds.add(targetId);
					}
					
					// 자기 자신까지 포함
					answer.append((result + 1) % 10);
				}
			}
			
			answer.append("\n");
		}
		
		// 정답 출력
		System.out.println(answer.toString());
		br.close();
	}

	private static int bfs(final int startRow, final int startCol, final int id) {
		LinkedList<int[]> queue = new LinkedList<>();
		queue.add(new int[] {startRow, startCol});
		Map[startRow][startCol] = id;

		int numOfEmpties = 1;
		while (!queue.isEmpty()) {
			int[] node = queue.poll();
			int row = node[0], col = node[1];
			
			for (int i = 0; i < DIRECTION_COUNT; i++) {
				int nextRow = row + ROW_DIRS[i];
				int nextCol = col + COL_DIRS[i];
				
				if (nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= M)	continue;
				if (Map[nextRow][nextCol] != 0)	continue;

				Map[nextRow][nextCol] = id;
				queue.add(new int[] {nextRow, nextCol});
				numOfEmpties++;
			}
		}
		
		return numOfEmpties;
	}
}