import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

	private static int N;
	private static char[][] Map;
	private static ArrayList<int[]> TeacherPositions;
	private static final int[] ROW_DIRS = { -1, 1, 0, 0 };
	private static final int[] COL_DIRS = { 0, 0, -1, 1 };
	private static boolean isFindAnswer;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		Map = new char[N][N];
		TeacherPositions = new ArrayList<>();

		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());

			for (int j = 0; j < N; j++) {
				Map[i][j] = st.nextToken().charAt(0);

				// 선생 위치 저장
				if (Map[i][j] == 'T')
					TeacherPositions.add(new int[] { i, j });
			}
		}

		// 2차원 조합
		combination(0, 0);
		String answer = (isFindAnswer) ? "YES" : "NO";

		System.out.println(answer);
		br.close();
	}

	// 1차원 배열로 변환한 2차원 조합 방법
	private static void combination(int index, int count) {
		if (isFindAnswer)
			return;

		if (count == 3) {
			if (isAllPass())	isFindAnswer = true;
			return;
		}

		// 더 이상 설치할 공간이 없는 경우
		if (index >= N * N)
			return;

		int row = index / N;
		int col = index % N;

		// 현재 위치가 빈 칸일 경우
		if (Map[row][col] == 'X') {
			Map[row][col] = 'O';
			combination(index + 1, count + 1);
			Map[row][col] = 'X';
		}

		// 현재 위치에 장애물을 설치하지 않는 경우
		combination(index + 1, count);
	}

	private static boolean isAllPass() {
		for (int[] position : TeacherPositions) {
			for (int i = 0; i < 4; i++) {
				int row = position[0] + ROW_DIRS[i], col = position[1] + COL_DIRS[i];

				while (isInMap(row, col) && Map[row][col] != 'O') {
					if (Map[row][col] == 'S')
						return false;
					row += ROW_DIRS[i];
					col += COL_DIRS[i];
				}
			}
		}

		return true;
	}

	private static boolean isInMap(int row, int col) {
		return row >= 0 && row < N && col >= 0 && col < N;
	}
}