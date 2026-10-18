#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


double calculate_Q(double x) {
    if (x < 6.2) {
        
        return 3.0 * (x - 6.2) + 10.0;
    }
    else if (x >= 6.2 && x <= 7.8) {
        
        return 2.0 * sqrt(fabs(x - 7.0 + 1.0)) + 45.0;
    }
    else {
        
        return (pow((x - 7.8), 2.0) / 1.0) + 55.0;
    }
}


int compare(const void* a, const void* b) {
    double arg1 = *(const double*)a;
    double arg2 = *(const double*)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int main() {
    
    setlocale( LC_ALL, "RUS");

    printf("--- Âàðèàíò 5. Ìîíèòîðèíã ðåàêòîðà ---\n\n");

    
    double test_x = 7.64;
    double test_q = calculate_Q(test_x);
    printf("1. Êîíòðîëüíûé ïðèìåð:\n");
    printf("   X = %.2f -> Q = %.4f (Îæèäàåòñÿ: 47.56)\n", test_x, test_q);

    
    if (fabs(test_q - 47.56) <= 0.01) {
        printf("   [OK] Òåñò ïðîéäåí.\n\n");
    }
    else {
        printf("   [ERROR] Òåñò íå ïðîéäåí!\n\n");
    }

    
    const int N = 50;
    double measurements[50];
    double q_values[50];
    double sum_q = 0.0;

    
    srand((unsigned)time(NULL));

    printf("2. Ãåíåðàöèÿ %d èçìåðåíèé è ðàñ÷åò Q:\n", N);
    printf("   %-10s | %-10s | %-10s | %s\n", "¹", "pH (X)", "Q(X)", "Ñòàòóñ (UCL=63)");
    printf("   ------------------------------------------------\n");

    for (int i = 0; i < N; i++) {
        
        double x = (rand() % 800) / 100.0 + 3.0;

        measurements[i] = x;
        double q = calculate_Q(x);
        q_values[i] = q;
        sum_q += q;

        
        char status[50] = "Íîðìà";
        if (q > 63.00) {
            sprintf_s(status, 50, "Ïðåâûøåíèå UCL!");
        }

        
        if (i < 5) {
            printf("   %-10d | %-10.2f | %-10.2f | %s\n", i + 1, x, q, status);
        }
        else if (i == 5) {
            printf("   ... (îñòàëüíûå äàííûå ñêðûòû äëÿ êðàòêîñòè)\n");
        }

        
        if (q > 63.00) {
            printf("   >> ÀÂÀÐÈß: Èçìåðåíèå #%d (X=%.2f) äàëî Q=%.2f > 63.00\n", i + 1, x, q);
        }
    }

    
    qsort(q_values, N, sizeof(double), compare);

    double median;
    if (N % 2 == 0) {
        
        median = (q_values[N / 2 - 1] + q_values[N / 2]) / 2.0;
    }
    else {
        median = q_values[N / 2];
    }

    double mean = sum_q / N;

    printf("\n3. Ñòàòèñòè÷åñêèé àíàëèç:\n");
    printf("   Ñðåäíåå çíà÷åíèå Q: %.4f\n", mean);
    printf("   Ìåäèàíà Q:          %.4f\n", median);

    
    printf("\n4. Äîïîëíèòåëüíîå çàäàíèå (àíàëèç):\n");
    printf("   Ìèíèìàëüíîå Q: %.4f\n", q_values[0]);
    printf("   Ìàêñèìàëüíîå Q: %.4f\n", q_values[N - 1]);

    printf("\nÍàæìèòå ëþáóþ êëàâèøó äëÿ âûõîäà...\n");
    getchar(); 
    return 0;
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


double calculate_Q(double x) {
    if (x < 6.2) {
        
        return 3.0 * (x - 6.2) + 10.0;
    }
    else if (x >= 6.2 && x <= 7.8) {
        
        return 2.0 * sqrt(fabs(x - 7.0 + 1.0)) + 45.0;
    }
    else {
        
        return (pow((x - 7.8), 2.0) / 1.0) + 55.0;
    }
}


int compare(const void* a, const void* b) {
    double arg1 = *(const double*)a;
    double arg2 = *(const double*)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int main() {
    
    setlocale( LC_ALL, "RUS");

    printf("--- Вариант 5. Мониторинг реактора ---\n\n");

    
    double test_x = 7.64;
    double test_q = calculate_Q(test_x);
    printf("1. Контрольный пример:\n");
    printf("   X = %.2f -> Q = %.4f (Ожидается: 47.56)\n", test_x, test_q);

    
    if (fabs(test_q - 47.56) <= 0.01) {
        printf("   [OK] Тест пройден.\n\n");
    }
    else {
        printf("   [ERROR] Тест не пройден!\n\n");
    }

    
    const int N = 50;
    double measurements[50];
    double q_values[50];
    double sum_q = 0.0;

    
    srand((unsigned)time(NULL));

    printf("2. Генерация %d измерений и расчет Q:\n", N);
    printf("   %-10s | %-10s | %-10s | %s\n", "№", "pH (X)", "Q(X)", "Статус (UCL=63)");
    printf("   ------------------------------------------------\n");

    for (int i = 0; i < N; i++) {
        
        double x = (rand() % 800) / 100.0 + 3.0;

        measurements[i] = x;
        double q = calculate_Q(x);
        q_values[i] = q;
        sum_q += q;

        
        char status[50] = "Норма";
        if (q > 63.00) {
            sprintf_s(status, 50, "Превышение UCL!");
        }

        
        if (i < 5) {
            printf("   %-10d | %-10.2f | %-10.2f | %s\n", i + 1, x, q, status);
        }
        else if (i == 5) {
            printf("   ... (остальные данные скрыты для краткости)\n");
        }

        
        if (q > 63.00) {
            printf("   >> АВАРИЯ: Измерение #%d (X=%.2f) дало Q=%.2f > 63.00\n", i + 1, x, q);
        }
    }

    
    qsort(q_values, N, sizeof(double), compare);

    double median;
    if (N % 2 == 0) {
        
        median = (q_values[N / 2 - 1] + q_values[N / 2]) / 2.0;
    }
    else {
        median = q_values[N / 2];
    }

    double mean = sum_q / N;

    printf("\n3. Статистический анализ:\n");
    printf("   Среднее значение Q: %.4f\n", mean);
    printf("   Медиана Q:          %.4f\n", median);

    
    printf("\n4. Дополнительное задание (анализ):\n");
    printf("   Минимальное Q: %.4f\n", q_values[0]);
    printf("   Максимальное Q: %.4f\n", q_values[N - 1]);

    printf("\nНажмите любую клавишу для выхода...\n");
    getchar(); 
    return 0;
}
