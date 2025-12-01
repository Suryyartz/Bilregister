#include <stdio.h>
#include <math.h>

int main() {
    int n;
    double x[100], sum = 0, mean, sd = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
        sum += x[i];
    }

    mean = sum / n;

    for (int i = 0; i < n; i++) {
        sd += (x[i] - mean) * (x[i] - mean);
    }

    if (n > 1)
        sd = sqrt(sd / (n - 1));
    else
        sd = 0;

    printf("%lf\n", sd);

    return 0;
}


