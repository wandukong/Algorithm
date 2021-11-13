package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 모노미노도미노2_20061 {

	static int[][] arr = new int[11][11];
	static int score = 0;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int cnt = 0;
		while (N-- > 0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int t = Integer.parseInt(st.nextToken());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());

			if (t == 1) { // 1x1
				// 파란색 보드로 이동
				int ny = 0;
				for (int i = 4; i < 10; i++)
					if (arr[x][i] == 0)
						ny = i;
					else
						break;
				arr[x][ny] = 1;

				// 초록색 보드로 이동
				int nx = 0;
				for (int i = 4; i < 10; i++)
					if (arr[i][y] == 0)
						nx = i;
					else
						break;
				arr[nx][y] = 1;

				// 파란색 보드 확인
				int y2 = 9;
				int cnt2 = 0;
				while (cnt2++ < 4) {
					boolean chk = true;
					for (int j = 0; j < 4; j++)
						if (arr[j][y2] == 0)
							chk = false;
					if (chk) {
						score++;
						for (int j = y2; j >= 5; j--) {
							arr[0][j] = arr[0][j - 1];
							arr[1][j] = arr[1][j - 1];
							arr[2][j] = arr[2][j - 1];
							arr[3][j] = arr[3][j - 1];
						}
						arr[0][4] = arr[1][4] = arr[2][4] = arr[3][4] = 0;
						ny++;
					} else
						y2--;
				}

				// 초록색 보드 확인
				int x2 = 9;
				cnt2 = 0;
				while (cnt2++ < 4) {
					boolean chk = true;
					for (int j = 0; j < 4; j++)
						if (arr[x2][j] == 0)
							chk = false;
					if (chk) {
						for (int j = x2; j >= 5; j--) {
							arr[j][0] = arr[j-1][0];
							arr[j][1] = arr[j-1][1];
							arr[j][2] = arr[j-1][2];
							arr[j][3] = arr[j-1][3];
						}
						arr[4][0] = arr[4][1] = arr[4][2] = arr[4][3] = 0;
						score++;
						nx++;
					} else
						x2--;
				}

				if (ny == 5) { // 파란색 특별한칸에 있는 경우
					for (int i = 9; i >= 6; i--) {
						arr[0][i] = arr[0][i - 1];
						arr[1][i] = arr[1][i - 1];
						arr[2][i] = arr[2][i - 1];
						arr[3][i] = arr[3][i - 1];
					}
					arr[x][5] = 0;
				}

				if (nx == 5) { // 초록색 특별한칸에 있는 경우
					for (int i = 9; i >= 6; i--) {
						arr[i][0] = arr[i - 1][0];
						arr[i][1] = arr[i - 1][1];
						arr[i][2] = arr[i - 1][2];
						arr[i][3] = arr[i - 1][3];
					}
					arr[5][y] = 0;
				}

			} else if (t == 2) { // 1x2

				// 파란색 보드로 이동
				int ny = 0;
				for (int i = 4; i < 10; i++)
					if (arr[x][i] == 0)
						ny = i;
					else
						break;
				arr[x][ny] = 1;
				arr[x][ny - 1] = 1;

				// 초록색 보드로 이동
				int nx = 0;
				for (int i = 4; i < 10; i++)
					if (arr[i][y] == 0 && arr[i][y + 1] == 0)
						nx = i;
					else
						break;
				arr[nx][y] = 1;
				arr[nx][y + 1] = 1;

				// 파란색 보드 확인
				int y2 = 9;
				int cnt2 = 0;
				while (cnt2++ < 4) {
					boolean chk = true;
					for (int j = 0; j < 4; j++)
						if (arr[j][y2] == 0)
							chk = false;
					if (chk) {
						score++;
						for (int j = y2; j >= 5; j--) {
							arr[0][j] = arr[0][j - 1];
							arr[1][j] = arr[1][j - 1];
							arr[2][j] = arr[2][j - 1];
							arr[3][j] = arr[3][j - 1];
						}
						arr[0][4] = arr[1][4] = arr[2][4] = arr[3][4] = 0;
						ny++;
					} else
						y2--;
				}

				// 초록색 보드 확인
				int x2 = 9;
				cnt2 = 0;
				while (cnt2++ < 4) {
					boolean chk = true;
					for (int j = 0; j < 4; j++)
						if (arr[x2][j] == 0)
							chk = false;
					if (chk) {
						for (int j = x2; j >= 5; j--) {
							arr[j][0] = arr[j-1][0];
							arr[j][1] = arr[j-1][1];
							arr[j][2] = arr[j-1][2];
							arr[j][3] = arr[j-1][3];
						}
						arr[4][0] = arr[4][1] = arr[4][2] = arr[4][3] = 0;
						score++;
						nx++;
					} else
						x2--;
				}

				if (ny == 6) { // 파란색 특별한칸에 한칸만 걸쳐있는 경우
					for (int i = 9; i >= 6; i--) {
						arr[0][i] = arr[0][i - 1];
						arr[1][i] = arr[1][i - 1];
						arr[2][i] = arr[2][i - 1];
						arr[3][i] = arr[3][i - 1];
					}
					arr[x][5] = 0;
				} else if (ny == 5) { // 파란색 특별한칸에 두칸에 걸쳐있는 경우
					for (int j = 1; j >= 0; j--)
						for (int i = 9; i >= 6 - j; i--) {
							arr[0][i] = arr[0][i - 1];
							arr[1][i] = arr[1][i - 1];
							arr[2][i] = arr[2][i - 1];
							arr[3][i] = arr[3][i - 1];
						}
					arr[x][5] = 0;
					arr[x][4] = 0;
				}

				if (nx == 5) { // 초록색 특별한칸에 있는 경우
					for (int i = 9; i >= 6; i--) {
						arr[i][0] = arr[i - 1][0];
						arr[i][1] = arr[i - 1][1];
						arr[i][2] = arr[i - 1][2];
						arr[i][3] = arr[i - 1][3];
					}
					arr[5][y] = 0;
					arr[5][y + 1] = 0;
				}

			} else if (t == 3) { // 2x1
				// 파란색 보드로 이동
				int ny = 0;
				for (int i = 4; i < 10; i++)
					if (arr[x][i] == 0 && arr[x + 1][i] == 0)
						ny = i;
					else
						break;
				arr[x][ny] = 1;
				arr[x + 1][ny] = 1;
				// 초록색 보드로 이동
				int nx = 0;
				for (int i = 4; i < 10; i++)
					if (arr[i][y] == 0)
						nx = i;
					else
						break;
				arr[nx][y] = 1;
				arr[nx - 1][y] = 1;

				// 파란색 보드 확인
				int y2 = 9;
				int cnt2 = 0;
				while (cnt2++ < 4) {
					boolean chk = true;
					for (int j = 0; j < 4; j++)
						if (arr[j][y2] == 0)
							chk = false;
					if (chk) {
						score++;
						for (int j = y2; j >= 5; j--) {
							arr[0][j] = arr[0][j - 1];
							arr[1][j] = arr[1][j - 1];
							arr[2][j] = arr[2][j - 1];
							arr[3][j] = arr[3][j - 1];
						}
						arr[0][4] = arr[1][4] = arr[2][4] = arr[3][4] = 0;
						ny++;
					} else
						y2--;
				}

				// 초록색 보드 확인
				int x2 = 9;
				cnt2 = 0;
				while (cnt2++ < 4) {
					boolean chk = true;
					for (int j = 0; j < 4; j++)
						if (arr[x2][j] == 0)
							chk = false;
					if (chk) {
						for (int j = x2; j >= 5; j--) {
							arr[j][0] = arr[j-1][0];
							arr[j][1] = arr[j-1][1];
							arr[j][2] = arr[j-1][2];
							arr[j][3] = arr[j-1][3];
						}
						arr[4][0] = arr[4][1] = arr[4][2] = arr[4][3] = 0;
						score++;
						nx++;
					} else
						x2--;
				}

				if (ny == 5) { // 파란색 특별한 칸에 걸쳐있는 경우
					for (int i = 9; i >= 6; i--) {
						arr[0][i] = arr[0][i - 1];
						arr[1][i] = arr[1][i - 1];
						arr[2][i] = arr[2][i - 1];
						arr[3][i] = arr[3][i - 1];
					}
					arr[x][5] = 0;
					arr[x + 1][5] = 0;
				}

				if (nx == 6) { // 초록색 특별한칸에 있는 경우
					for (int i = 9; i >= 6; i--) {
						arr[i][0] = arr[i - 1][0];
						arr[i][1] = arr[i - 1][1];
						arr[i][2] = arr[i - 1][2];
						arr[i][3] = arr[i - 1][3];
					}
					arr[5][y] = 0;
				} else if (nx == 5) { // 초록색 특별한칸에 있는 경우
					for (int j = 0; j < 2; j++)
						for (int i = 9; i >= 6 - j; i--) {
							arr[i][0] = arr[i - 1][0];
							arr[i][1] = arr[i - 1][1];
							arr[i][2] = arr[i - 1][2];
							arr[i][3] = arr[i - 1][3];
						}
					arr[5][y] = 0;
					arr[4][y] = 0;
				}
			}
		}
		// 파란색 보드 확인
		for (int i = 0; i < 4; i++)
			for (int j = 6; j < 10; j++)
				if (arr[i][j] == 1)
					cnt++;

		// 초록색 보드 확인
		for (int i = 6; i < 10; i++)
			for (int j = 0; j < 4; j++)
				if (arr[i][j] == 1)
					cnt++;

		System.out.println(score);
		System.out.println(cnt);
	}
}
