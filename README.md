# nhf3

1. Feladat: dual_sort (40 pont)
-------------------------------
Készítsd el a dual_sort-h-ban a dual_sort implementációját a megadott keretrendszerben!
Az algoritmus implementálásához felhasználhatod az órai kódokat is illetve a
standard library által nyújtott lehetőségeket kivéve az std::sort-ot!
A dual_sort egy hibrid rendezőalgoritmus.
Alapvetően egy gyorsrendezőként indul, de ha a rekurzió túl mélyre jut egy kupacrendezőre vált
a worst-case O(n2) elkerülése érdekében.

Tehát a dual_sort:
• Ha a gyorsrendező rekurziójának mélysége elér egy határt akkor a dual_sort kupacrendezőre 
vált és a maradék részt kupacrendezéssel rendezi. Ez a határ 2*log2(N).

Megvalósítandó feladat: dual_sort.h-ban implementáld:
• void dual_sort(std::vector<int> &data, int N) eljárást
o bemenete egy int típusú vektor és a vektor hossza
o a vektort növekvő sorrendbe rendezetten adja vissza
Egyéb segédfüggvényeket lehet használni.