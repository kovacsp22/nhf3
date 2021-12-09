# 3. NAGY HAZI

1. Feladat: dual_sort (40 pont)
Készítsd el a dual_sort-h-ban a dual_sort implementációját a megadott keretrendszerben!
Az algoritmus implementálásához felhasználhatod az órai kódokat is illetve a
standard library által nyújtott lehetőségeket kivéve az std::sort-ot!
A dual_sort egy hibrid rendezőalgoritmus.
Alapvetően egy gyorsrendezőként indul, de ha a rekurzió túl mélyre jut egy kupacrendezőre vált
a worst-case O(n2) elkerülése érdekében.

2. Feladat: n_dim_sort (60 pont)
Készítsd el az n_dim_sort.h-ban a sort_2D és sort_3D implementációját a dual_sort felhasználásával! 
A sort_2D és sort_3D algoritmusok az elemeket adott dimenzión az origóhoz viszonyított euklideszi 
távolság függvényében rendezi.
