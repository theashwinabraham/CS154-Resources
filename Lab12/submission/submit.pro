% ASHWIN ABRAHAM, 13/06/2022

mylast([A|[]], A).
mylast([_|B], E):- mylast(B, E).

removelast([_|[]], []).
removelast([A|B], [A|C]):- removelast(B, C).

myreverse([], []).
myreverse([A|[]], [A|[]]).
myreverse([A|B], [P|Q]):- mylast(B, P), mylast(Q, A), removelast(B, Z1), removelast(Q, Z2), myreverse(Z1, Z2).


palindrome([A|L]):-myreverse([A|L], [A|L]).

myappend([], L, L).
myappend([A|L], [B|U], [A|R]):- myappend(L, [B|U], R).