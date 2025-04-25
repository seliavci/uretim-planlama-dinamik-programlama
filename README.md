Üretim Planlama Problemi - Dinamik Programlama Çözümü

Problem Tanımı ve Matris Zinciri Çarpımı ile İlişkisi

Bu çalışmada, bir üretim hattındaki işleri sıralı şekilde minimum sürede tamamlamak için dinamik programlama yaklaşımıyla çözüm önerilmektedir. Problemde, her biri belirli bir sırada tamamlanması gereken n adet iş ve bu işleri yapabilecek m farklı makine bulunmaktadır. Her işin, her makinede tamamlanma süresi farklıdır. Ayrıca, bir işin bir makinede tamamlandıktan sonra, bir sonraki işin başka bir makinede yapılması durumunda makineler arası geçiş maliyeti söz konusudur. Bu maliyet, makine ayar süresi, taşıma süresi gibi faktörlerden oluşabilir.

Amacımız, tüm işleri sırayla tamamlamak için gereken toplam süreyi (iş süresi + geçiş süresi) en aza indirmektir.

Bu problem, klasik Matris Zinciri Çarpımı problemiyle benzerlik gösterir. Matris zinciri çarpımında amaç, çok sayıda matrisi hangi sırayla çarparsak toplam işlem maliyeti (skaler çarpım sayısı) en az olur, sorusuna cevap bulmaktır. Burada da, her iş bir matris gibi düşünülebilir. Makine seçimi ise matris çarpımındaki parantezleme sırası gibi davranır.

Benzerlik Noktaları:
Kararların Sonraki İşlemleri Etkilemesi: Matris zinciri çarpımında her karar, sonraki işlemleri etkiler. Burada da seçilen makine, sonraki işlerdeki geçiş süresini etkiler.
Alt Problemlerin Optimal Çözümü İçin Birleştirilmesi: Alt problemler optimal çözüm için birleştirilir. (Optimal Alt Yapı)
Alt Problemlerin Tekrar Etmesi: Alt problemler tekrarlanır. (Overlapping Subproblems)
Bu nedenle, bu problem dinamik programlama ile çözülebilir.

Tablolama ve Hafızalama Algoritmasının Açıklaması

Bu üretim planlama problemi, alt problemlerin tekrarlanması ve optimal alt yapı özelliklerini taşıdığı için dinamik programlama ile çözülmeye uygundur. Çözüm yaklaşımında, iki temel kavram kullanılacaktır:

Tablolama (Tabulation): Alt problemlerin çözüm sonuçlarını bir tablo (genelde 2 boyutlu dizi) içinde saklayarak daha büyük problemleri çözmek.
Hafızalama (Memoization): Daha çok geri dönüşümlü (recursive) çözümde kullanılır. Bu projede tablolama yaklaşımı tercih edilmiştir çünkü sıralı işler yapılıyor ve ileriye doğru ilerlemek daha doğaldır.
Temel Kavramlar

n: Yapılacak iş sayısı (örneğin 4 iş)
m: Kullanılabilir makine sayısı (örneğin 3 makine)
time[i][j]: i numaralı işin j numaralı makinede tamamlanma süresi
transition[j][k]: j numaralı makineden k numaralı makineye geçiş süresi
DP Tablosu

dp[i][j]: i numaralı işin j numaralı makinede yapılması durumundaki minimum toplam süreyi tutar.
Geçiş Durumu (Recurrence Relation)

dp[i][j] = min(dp[i-1][k] + transition[k][j]) + time[i][j]
Burada:

Önceki iş (i-1) k makinesinde yapılmış olsun.
Şu anki iş (i) j makinesinde yapılacak.
Geçiş süresi: transition[k][j]
Toplam süre: önceki minimum + geçiş + bu işin süresi
Başlangıç (Base Case)

İlk iş için geçiş maliyeti yoktur. Bu yüzden:

dp[0][j] = time[0][j]
Bu, ilk işin her makinedeki süresidir.

Sonuç olarak, minimum toplam süre şu şekilde bulunur:

min(dp[n-1][j]) for all 0 <= j < m
Yani, son işin tüm makinelerdeki minimum bitirme süresi hesaplanarak en uygun çözüm elde edilir.

