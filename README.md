retim-planlama-dinamik-programlama
Geçiş maliyetleriyle birlikte üretim planlaması için dinamik programlama çözümü.

# Üretim Planlama - Dinamik Programlama Yaklaşımı

Bu proje, Algoritma Analizi ve Tasarımı dersi kapsamında, dinamik programlama kullanılarak bir üretim planlaması problemi çözümünü içermektedir. 
Amaç, işlerin makineler üzerinde sırayla işlenmesi sürecinde toplam süreyi minimize etmektir. 
Makineler arasında geçiş maliyetleri de hesaba katılmaktadır.

Problem Tanımı

- Toplamda `n` adet iş vardır. Her iş sıralı şekilde yapılmak zorundadır.
- Bu işler `m` farklı makinede yapılabilir.
- Her işin her makinedeki işlem süresi farklıdır.
- Makineler arasında geçiş yapılırsa bir geçiş maliyeti ortaya çıkar. (örneğin ayar süresi, taşıma süresi vs.)
- Amaç, tüm işleri minimum toplam sürede tamamlayacak optimum makine seçim sırasını bulmaktır.

Problem ve Matris Zinciri Çarpımı İlişkisi

Bu problem, matris zinciri çarpımı problemine benzerlik göstermektedir:
- Her karar bir sonraki işin hangi makinada yapılacağını etkiler.
- Alt problemlerin optimal çözümü, genel çözümde kullanılır.
- Bu nedenle dinamik programlama en uygun yaklaşımdır.

Kullanılan Yaklaşım: Tablolama (Bottom-Up)

Projede tablolama yöntemi (bottom-up DP) kullanılmıştır. Nedeni:
- Tüm olası durumlar (iş × makine) iteratif olarak hesaplanmalı,
- Önce küçük alt problemler çözülerek tabloya yazılır,
- Sonuçlar tablo üzerinden ilerletilir.

Hafızalama (memoization) da bir seçenekti ancak bu problemde durumların tamamı gerektiği için tablolama daha uygundur.

Algoritmanın Açıklaması

1. `n` iş ve `m` makine için bir `dp[i][j]` tablosu oluşturulur.
   - `i`: iş numarası (0'dan n-1'e kadar)
   - `j`: makine numarası (0'dan m-1'e kadar)
   - `dp[i][j]`: i. işin j. makinada bitmesi durumundaki minimum toplam süre
2. İlk iş için doğrudan işlem süreleri alınır.
3. Sonraki işler için:
   - Önceki işin hangi makinada yapıldığına göre geçiş maliyeti eklenir.
   - Minimum toplam süre olacak şekilde tablo güncellenir.
4. Son satırdaki en küçük değer, minimum toplam süredir.

Girdi Formatı

- `processing_time[i][j]`: i. işin j. makinadaki süresi
- `transition_cost[j1][j2]`: j1'den j2'ye geçişin maliyeti

Örnek Girdi

```python
processing_time = [
    [5, 8, 6],
    [4, 7, 3],
    [6, 5, 4],
    [3, 8, 6]
]

transition_cost = [
    [0, 2, 4],
    [2, 0, 3],
    [4, 3, 0]
]

Örnek Çıktı:
Minimum toplam süre: 21


Zaman ve Uzay Karmaşıklığı

Zaman Karmaşıklığı: O(n × m × m)
(Her iş için her makineden diğer tüm makinelere geçiş denetleniyor.)

Uzay Karmaşıklığı: O(n × m)
(DP tablosu iş × makine boyutunda.)


























