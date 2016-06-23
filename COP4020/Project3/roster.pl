/* John Stubbs */
/* jas12y      */

menu(X) :- 
   write('\tClass roster management system'), nl,
   write('\t=============================='), nl,
   write('\t   MENU'), nl,
   write('\t=============================='), nl,
   write('\t0. Reset roster'), nl,
   write('\t1. Load roster from file'), nl,
   write('\t2. Store roster to file'), nl, 
   write('\t3. Display roster sorted by ID'), nl, 
   write('\t4. Display roster sorted by name'), nl, 
   write('\t5. Display roster sorted by grade'), nl, 
   write('\t6. Add a student to roster'), nl, 
   write('\t7. Remove a student from roster'), nl, 
   write('\t8. Exit'), nl, 
   write('\tEnter your choice (followed by a \'.\'): '),
   read(Sel),
   process(Sel, X).

process(0, _) :-
    nl,
    write('\tReset roster (now empty).'),nl,
    nl, nl, menu([]).

process(1, _) :-
    nl,
    write('\tEnter a filename to load roster from: '),
    read(File),
    write('\n'),
    see(File),
    read(X),
    seen,
    nl, nl, menu(X).

process(2, X) :-
    nl,
    write('\tEnter a filename to stroe roster to: '),
    read(File),
    write('\n'),
    tell(File),
    write(X),
    write('.'), 
    told,
    nl, nl, menu(X).

process(3, X) :-
    nl,
    write('\tDisplay roster sorted by ID.'),nl,
    sort_id(X, Sorted),
    display_records(1, Sorted),
    nl, nl, menu(Sorted).

process(4, X) :-
    nl,
    write('\tDisplay roster sorted by name.'),nl,
    sort_name(X, Sorted),
    display_records(1, Sorted),
    nl, nl, menu(Sorted).

process(5, X) :-
    nl,
    write('\tDisplay roster sorted by grade.'),nl,
    sort_grade(X, Sorted),
    display_records(1, Sorted),
    nl, nl, menu(Sorted).

process(6, X) :- 
    nl,
    write('\tAdd a student to the class roster.'),nl,nl,
    read_student_info([A, B, C]),
    nl, nl, menu([[A,B,C] | X]).

process(7, X) :- 
    nl,
    write('\tRemove a student from the class roster.'),nl,
    write('\tEnter a student name or ID: '),
    read(Y),
    remove(Y,X,L),
    nl, nl, menu(L).

process(8, _) :- write('Good-bye!'), nl, !.
process(_, X) :- menu(X).

read_student_info([A, B, C]) :-
    write('\tStudent ID: '),
    read(A),
    write('\tStudent Name: '),
    read(B),
    write('\tGrade: '),
    read(C).

display_records(1, []):-write('\tNo records to display.').
display_records(_, []).
display_records(Num, [[ID, Name, Grade] | L]) :-
    write('\tNo.'),
    write(Num),
    write(': ID = '),
    write(ID),
    write(', Name = '),
    format('~s', [Name]),
    write(', Grade = '),
    write(Grade),
    write('\n'),
    N is Num + 1,
    display_records(N, L).

sort_id(List,Sorted):-perm(List,Sorted),is_sorted_id(Sorted).
sort_name(List,Sorted):-perm(List,Sorted),is_sorted_name(Sorted).
sort_grade(List,Sorted):-perm(List,Sorted),is_sorted_grade(Sorted).

is_sorted_id([]).
is_sorted_id([_]).
is_sorted_id([X,Y|T]):-X=[A|_],Y=[B|_],A=<B,is_sorted_id([Y|T]).

is_sorted_name([]).
is_sorted_name([_]).
is_sorted_name([X,Y|T]):-X=[_,[A|_]|_],Y=[_,[B|_]|_],A=<B,is_sorted_name([Y|T]).

is_sorted_grade([]).
is_sorted_grade([_]).
is_sorted_grade([X,Y|T]):-X=[_,_,A|_],Y=[_,_,B|_],A=<B,is_sorted_grade([Y|T]).

perm(List,[H|Perm]):-takeout(H,List,Rest),perm(Rest,Perm).
perm([],[]).

takeout(X,[X|T],T).
takeout(X,[H|T],[H|NT]):-takeout(X,T,NT).

remove(X,[[X|_]|T],T):-write('\n\tStudent removed.').
remove(X,[[_,X|_]|T],T):-write('\n\tStudent removed.').
remove(_,[],[]):-write('\n\tStudent does not exist.').
remove(X,[H|T],[H|NT]):-remove(X,T,NT).

