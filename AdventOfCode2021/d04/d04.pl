read_seq(Seq, Sep, Pad, Stream) :-
    read_line_to_string(Stream, String),
    split_string(String, Sep, Pad, StrSeq),
    maplist(atom_number, StrSeq, Seq).

read_board([], 0, _).
read_board(Board, X, Stream) :-
    X > 0,
    read_seq(Seq, " ", " ", Stream),
    Y is X - 1,
    read_board(B, Y, Stream),
    append([Seq], B, Board).

read_boards(Boards, Stream) :- 
    read_line_to_string(Stream, Line),
    (
        Line = end_of_file ->
        Boards = [] ;
        read_board(Board, 5, Stream),
        read_boards(Rest, Stream),
        append([Board], Rest, Boards)
    ).

rowSolved(Row, Seq) :- forall(member(A, Row), member(A, Seq)).
anyRow([R|Rest], Seq) :- rowSolved(R, Seq); anyRow(Rest, Seq).

getCol([], _, []). 
getCol([H|T], Col, Res) :-
    nth0(Col, H, X),
    getCol(T, Col, Sub),
    append([X], Sub, Res).

anyCol(Board, Seq) :-
    length(Board, NR),
    NR > 0,
    [H|_] = Board,
    length(H, NC),
    NCM1 is NC - 1,
    between(0, NCM1, X),
    getCol(Board, X, Col),
    rowSolved(Col, Seq).

boardSolved(Board, Seq) :- anyRow(Board, Seq); anyCol(Board, Seq).

anyBoard(Boards, Seq, Board) :- member(Board, Boards), boardSolved(Board, Seq).

boardScore(Board, Seq, Score) :-
    length(Seq, SL),
    nth1(SL, Seq, New),
    flatten(Board, Flat),
    exclude({Seq}/[X]>>member(X, Seq), Flat, Unseen),
    sum_list(Unseen, UnseenSum),
    Score is UnseenSum * New.

firstMatch([H|T], Goal, Res) :- call(Goal, H, Res); firstMatch(T, Goal, Res).

prefGen(_, [], []).
prefGen(Pre, [H|T], [NPre|Rest]) :- append(Pre, [H], NPre), prefGen(NPre, T, Rest).
prefs(Pre, Prefs) :- prefGen([], Pre, Prefs).

firstBoard(Seq, Boards, Score) :-
    prefs(Seq, Prefs),
    firstMatch(Prefs, {Boards}/[X,S]>>(anyBoard(Boards, X, Board), boardScore(Board, X, S)), Score).

lastBoard(Seq, Boards, Score) :-
    prefs(Seq, Prefs),
    reverse(Prefs, Rev),
    firstMatch(Rev,
        {Boards} / [X, S] >> (
            length(X, L),
            nth1(L, X, _, Shorter),
            anyBoard(Boards, X, Board),
            not(anyBoard(Boards, Shorter, Board)),
            boardScore(Board, X, S)
        ),
        Score).

start(PartA, PartB) :-
    open("d04.txt", read, Stream),
    read_seq(Seq, ",", "", Stream),
    read_boards(Boards, Stream),
    firstBoard(Seq, Boards, PartA),
    lastBoard(Seq, Boards, PartB).
