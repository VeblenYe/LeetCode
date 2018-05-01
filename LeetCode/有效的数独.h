#pragma once


/* 有效的数独 */


#include <vector>
#include <set>

using std::vector;
using std::set;

/* 思路，直接检查，没啥其他思路 */


bool isValidSudoku(vector<vector<char>> &board) {
	set<char> s;

	for (auto i = 0; i < 9; i++) {		// 行
		for (auto j = 0; j < 9; j++) {
			if (board[i][j] == '.') continue;
			if ('1' <= board[i][j] && board[i][j] <= '9')
				if (s.find(board[i][j]) == s.end())
					s.insert(board[i][j]);
				else
					return false;
		}
		s.clear();
	}
	
	for (auto i = 0; i < 9; i++) {		// 列
		for (auto j = 0; j < 9; j++) {
			if (board[j][i] == '.') continue;
			if ('1' <= board[j][i] && board[j][i] <= '9')
				if (s.find(board[j][i]) == s.end())
					s.insert(board[j][i]);
				else
					return false;
		}
		s.clear();
	}

	for (int i = 0; i < 9; i++) {
		int col = (i / 3) * 3;
		int row = (i * 3) % 9;
		for (int j = col; j < col + 3; j++) {
			for (int k = row; row < row + 3; k++) {
				if (board[j][k] == '.') continue;
				if ('1' <= board[j][k] && board[j][k] <= '9')
					if (s.find(board[j][k]) == s.end())
						s.insert(board[j][k]);
					else
						return false;
			}
		}
		s.clear();
	}

	return true;

}
