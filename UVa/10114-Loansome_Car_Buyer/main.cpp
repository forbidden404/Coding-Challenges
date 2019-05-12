#include <iostream>
#include <vector>
#include <string>

int main() {
    int loanDuration;
    double downPayment;
    double loanAmount;
    int depreciationRecordNumbers;
    while (scanf("%d %lf %lf %d", &loanDuration, &downPayment, &loanAmount, &depreciationRecordNumbers) != EOF) {
        if (loanDuration < 0) return 0;

        int month[depreciationRecordNumbers];
        double depreciationPercentage[depreciationRecordNumbers];
        int i = 0;
        while (depreciationRecordNumbers--) {
            char depreciationString[128];
            scanf("%d %s", &month[i], depreciationString);
            depreciationPercentage[i++] = atof(depreciationString); 
        }

        int previousMonth = 0;
        double previousDepreciation = 0.0f;

        // Initial depreciation
        double carValue = loanAmount + downPayment;
        double monthlyPayment = loanAmount / loanDuration;
        if (month[0] == 0) {
            carValue *= (1 - depreciationPercentage[0]);
            previousDepreciation = depreciationPercentage[0];
            if (loanAmount < carValue) {
                // Finish
                printf("0 months\n");
                continue;
            }
        }

        // Monthly depreciation
        int actualMonth = 1;
        while (true) {
            loanAmount -= monthlyPayment;

            if (actualMonth == month[(previousMonth + 1)]) {
                previousDepreciation = depreciationPercentage[previousMonth + 1];
                previousMonth++;
            }
            
            carValue *= (1 - previousDepreciation);
            if (loanAmount < carValue) {
                printf("%d month%s", actualMonth, actualMonth != 1 ? "s\n" : "\n");
                break;
            }
            
            actualMonth++;
        }
    }
}
