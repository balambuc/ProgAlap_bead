#Versenyek győztesei rangsora

Egy iskolában egyéni és összetett tanulmányi versenyt tartottak. A versenyekben összesen N tanuló
vett részt. A versenyek száma M. Ismerjük versenyenként az induló tanulókat és elért pontszámukat.
Az összetett versenyben csak azon tanulók eredményét értékelik, akik az összes egyéni
versenyen indultak és elérték a versenyenként adott minimális pontszámot.
Készíts programot, amely megadja az egyéni versenyek győzteseinek rangsorát!

##Bemenet

A standard bemenet első sorában a tanulók száma (1≤N≤100) és a versenyek száma
(1≤M≤100) van. A második sorban az M versenyen elvárt minimális pontszámok találhatók
(0≤Mini≤50). Az ezt követő M sorban az egyes versenyek leírása következik: a versenyen indulók
száma (1≤Indi≤N), majd Indi számpár, az egyes tanulók sorszáma (1≤Si,j≤N) és elért
pontszáma (1≤Pi,j≤100).

##Kimenet

A standard kimenet első sorába az egyéni győzelmet elért tanulók T számát kell kiírni,
amelyet a T győztes sorszáma kövessen, győzelmek száma szerint csökkenő, azon belül sorszám
szerint növekvő sorrendben!


##Példa

Bemenet                     Kimenet
5 3                         3 4 2 5
10 10 10
3 1 10 2 30 3 10
2 4 50 1 30
5 1 10 2 20 3 30 4 50 5 50

##Korlátok

Időlimit: 0.1 mp.
Memórialimit: 32 MB
