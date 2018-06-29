class TicTacToe {
    public :
	TicTacToe(int n) {
	    _size = n;
	    board = new char*[n];
	    for (int i = 0 ; i < n ; ++i) {
		board[i] = new char[n]();
	    }
	}

	int move(int row, int col, int player) {
	    char tag = 'a' + player;
	    board[row][col] = tag;
	    int iter(0);
	    for (; iter < _size ; ++iter)
		if (board[row][iter] != tag) break;
	    if (iter == _size) return player;
	    for (iter = 0 ; iter < _size ; ++iter)
		if (board[iter][col] != tag) break;
	    if (iter == _size) return player;
	    if (0 == (row-col)) {
		for (iter = 0 ; iter < _size ; ++iter)
		    if (board[iter][iter] != tag) break;
		if (iter == _size) return player;
	    }
	    if ((_size-1) == (row + col)) {
		int x = 0, y = _size - 1;
		for (; x < _size && y >= 0 ; ++x, --y)
		    if (board[x][y] != tag) break;
		if (0 == y) return player;
	    }
	    return 0;
	}
    private :
	char **board;
	int _size;
        virtual ~TicTacToe() {}
        TicTacToe& operator=(const TicTacToe& source);
        TicTacToe(const TicTacToe&);
};

