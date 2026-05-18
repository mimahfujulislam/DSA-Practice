#include <iostream>
using namespace std;

int main() {
    const int n = 7;
    int weights[n] = {2, 3, 5, 7, 1, 4, 1};
    int profits[n] = {10, 5, 15, 7, 6, 18, 3};
    int totalWeight = 15;
    double ratio[n];
    for (int i = 0; i < n; i++) {
        ratio[i] = (double)profits[i] / weights[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                double tempRatio = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempRatio;

                int tempWeight = weights[j];
                weights[j] = weights[j + 1];
                weights[j + 1] = tempWeight;

                int tempProfit = profits[j];
                profits[j] = profits[j + 1];
                profits[j + 1] = tempProfit;
            }
        }
    }
    double totalProfit = 0.0;
    int currentWeight = 0;
    for (int i = 0; i < n; i++) {
        if (currentWeight + weights[i] <= totalWeight) {
            currentWeight += weights[i];
            totalProfit += profits[i];
        } else {
            int remainingWeight = totalWeight - currentWeight;
            totalProfit += profits[i] * ((double)remainingWeight / weights[i]);
            currentWeight += remainingWeight;
            break;
        }
    }
    cout<<"Given weights: ";
    for (int i = 0; i < n; i++) {
        cout << weights[i] << " ";
    }
    cout<<endl;
    cout << "Given profits: ";
    for (int i = 0; i < n; i++) {
        cout << profits[i] << " ";
    }
    cout<<endl;
    cout << "Total weight: " << currentWeight << endl;
    cout << "Maximum profit: " << totalProfit << endl;

    return 0;
}
