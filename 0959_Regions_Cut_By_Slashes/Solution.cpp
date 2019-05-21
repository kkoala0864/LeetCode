#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

typedef struct _direct {
    char value;
    int up;
    int down;
    int left;
    int right;
    _direct() : up(0), down(0), left(0), right(0) {}
} direct;

void render(vector<vector<direct>>& state, int x, int y, int ComeFrom, int& cnt);

void initial(const vector<string>& grid, vector<vector<direct>>& state) {
    int size = grid.size();
    for (int y = 0 ; y < size ; ++y) {
	for (int x = 0 ; x < size ; ++x) {
	    state.at(y).at(x).value = grid.at(y).at(x);
	}
    }
}

void renderSlashLuRd(vector<vector<direct>>& state, int x, int y, int ComeFrom, int& cnt) {
    if (1 == ComeFrom || 4 == ComeFrom || 0 == ComeFrom) {
	if (state.at(x).at(y).up == 0 && state.at(x).at(y).right == 0) {
	    if (0 == ComeFrom) ++cnt;
	    state.at(x).at(y).up = cnt;
	    state.at(x).at(y).right = cnt;
	    render(state, x, y-1, 3, cnt);
	    render(state, x+1, y, 2, cnt);
	}
    }
    if (2 == ComeFrom || 3 == ComeFrom || 0 == ComeFrom) {
	if (state.at(x).at(y).left == 0 && state.at(x).at(y).down == 0) {
	    if (0 == ComeFrom) ++cnt;
	    state.at(x).at(y).left = cnt;
	    state.at(x).at(y).down = cnt;
	    render(state, x-1, y, 4, cnt);
	    render(state, x , y+1, 1, cnt);
	}
    }
}

void renderSlashLdRu(vector<vector<direct>>& state, int x, int y, int ComeFrom, int& cnt) {
    if (1 == ComeFrom || 2 == ComeFrom || 0 == ComeFrom) {
	if (state.at(x).at(y).up == 0 && state.at(x).at(y).left == 0) {
	    if (0 == ComeFrom) ++cnt;
	    state.at(x).at(y).up = cnt;
	    state.at(x).at(y).left = cnt;
	    render(state, x, y-1, 3, cnt);
	    render(state, x-1, y, 4, cnt);
	}
    }
    if (3 == ComeFrom || 4 == ComeFrom || 0 == ComeFrom) {
	if (state.at(x).at(y).right == 0 && state.at(x).at(y).down == 0) {
	    if (0 == ComeFrom) ++cnt;
	    state.at(x).at(y).right = cnt;
	    state.at(x).at(y).down = cnt;
	    render(state, x+1, y, 2, cnt);
	    render(state, x , y+1, 1, cnt);
	}
    }
}

void renderBlank(vector<vector<direct>>& state, int x, int y, int ComeFrom, int& cnt) {
    if (0 == ComeFrom) ++cnt;
    state.at(x).at(y).up = cnt;
    state.at(x).at(y).down = cnt;
    state.at(x).at(y).left = cnt;
    state.at(x).at(y).right = cnt;
    render(state, x+1, y, 2, cnt);
    render(state, x-1, y, 4, cnt);
    render(state, x, y+1, 1, cnt);
    render(state, x, y-1, 3, cnt);
}

void render(vector<vector<direct>>& state, int x, int y, int ComeFrom, int& cnt) {
    int size = state.size();
    if (x >= size || x < 0 || y >= size || y < 0) return;
    if (state.at(x).at(y).value == ' ' && state.at(x).at(y).up == 0) {
	renderBlank(state, x, y, ComeFrom, cnt);
    } else if (state.at(x).at(y).value == '\\') {
	renderSlashLuRd(state, x, y, ComeFrom, cnt);
    } else {
	renderSlashLdRu(state, x, y, ComeFrom, cnt);
    }
}

int Solution::regionsBySlashes(vector<string>& grid) {
    int size = grid.size();
    vector<vector<direct>> state(size ,vector<direct>(size));
    initial(grid, state);
    int ret = 0;
    for (int x = 0 ; x < size ; ++x) {
	for (int y = 0 ; y < size ; ++y) {
	    if (state.at(x).at(y).value == ' ' && state.at(x).at(y).up == 0) {
		renderBlank(state, x, y, 0, ret);
	    } else if (state.at(x).at(y).value == '\\') {
		renderSlashLuRd(state, x, y, 0, ret);
	    } else {
		renderSlashLdRu(state, x, y, 0, ret);
	    }
	}
    }
    return ret;
}
