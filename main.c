//
//  main.c
//  UretimPlanlama
//
//  Created by Selin Avcı on 25.04.2025.
//
#include <stdio.h>
#include <limits.h>

#define N 4 // İş sayısı
#define M 3 // Makine sayısı

int main() {
    // İşlerin her bir makinedeki süreleri
    int time[N][M] = {
        {4, 6, 8},  // İş 0
        {5, 7, 3},  // İş 1
        {6, 4, 5},  // İş 2
        {3, 8, 6}   // İş 3
    };

    // Makine geçiş süreleri
    int transition[M][M] = {
        {0, 2, 3},
        {2, 0, 4},
        {3, 4, 0}
    };

    // Dinamik programlama tablosu
    int dp[N][M];

    // İlk işin her makinedeki başlangıç süreleri
    for (int j = 0; j < M; j++) {
        dp[0][j] = time[0][j];
    }

    // Dinamik programlama tablosunu doldurma
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int minPrev = INT_MAX;

            // Önceki işin yapıldığı makineleri kontrol et
            for (int k = 0; k < M; k++) {
                int cost = dp[i - 1][k] + transition[k][j];
                if (cost < minPrev) {
                    minPrev = cost;
                }
            }

            // Mevcut işin bu makinede tamamlanma süresini hesapla
            dp[i][j] = minPrev + time[i][j];
        }
    }

    // Minimum toplam süreyi bulma
    int result = INT_MAX;
    for (int j = 0; j < M; j++) {
        if (dp[N - 1][j] < result) {
            result = dp[N - 1][j];
        }
    }

    // Sonucu yazdır
    printf("Minimum toplam sure: %d\n", result);

    return 0;
}
