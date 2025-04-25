Problem Tanımı ve Matris Zinciri Çarpımı ile İlişkisi

Bu çalışmada, bir üretim hattındaki işleri sıralı şekilde minimum sürede tamamlamak için dinamik programlama yaklaşımıyla çözüm önerilmektedir. Problemde, her biri belirli bir sırada tamamlanması gereken n adet iş ve bu işleri yapabilecek m farklı makine bulunmaktadır. Her işin, her makinede tamamlanma süresi farklıdır. Ayrıca, bir işin bir makinede tamamlandıktan sonra, bir sonraki işin başka bir makinede yapılması durumunda makineler arası geçiş maliyeti söz konusudur. Bu maliyet; makine ayar süresi, taşıma süresi gibi değerlerden oluşabilir.

Amaç, tüm işleri sırayla tamamlamak için gereken toplam süreyi (iş süresi + geçiş süresi) en aza indirmektir.

Bu problem, klasik Matris Zinciri Çarpımı problemiyle benzerlik gösterir. Matris zinciri çarpımında amaç, çok sayıda matrisi hangi sırayla çarparsak toplam işlem maliyeti (skaler çarpım sayısı) en az olur, sorusuna cevap bulmaktır. Burada da, her iş bir matris gibi düşünülebilir. Makine seçimi ise matris çarpımındaki parantezleme sırası gibi davranır.

Benzerlik noktaları:

Matris zinciri çarpımında her karar, sonraki işlemleri etkiler. Burada da seçilen makine, sonraki işlerdeki geçiş süresini etkiler.
Alt problemler optimal çözüm için birleştirilir. (Optimal Alt Yapı)
Alt problemler tekrarlanır. (Overlapping Subproblems)
Bu nedenle, dinamik programlama ile çözülebilir.





















