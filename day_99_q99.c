#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    int speed;
} Car;

// Sort by position descending
int cmp(const void *a, const void *b) {
    return ((Car*)b)->pos - ((Car*)a)->pos;
}

int carFleet(int target, int position[], int speed[], int n) {
    Car cars[n];

    // Step 1: Combine data
    for (int i = 0; i < n; i++) {
        cars[i].pos = position[i];
        cars[i].speed = speed[i];
    }

    // Step 2: Sort by position descending
    qsort(cars, n, sizeof(Car), cmp);

    int fleets = 0;
    double lastTime = 0.0;

    // Step 3: Process cars
    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].pos) / cars[i].speed;

        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
    }

    return fleets;
}

int main() {
    int n, target;

    scanf("%d %d", &n, &target);

    int position[n], speed[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &position[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &speed[i]);
    }

    printf("%d\n", carFleet(target, position, speed, n));

    return 0;
}