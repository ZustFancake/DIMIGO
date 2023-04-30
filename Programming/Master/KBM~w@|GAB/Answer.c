#include <stdio.h>
#include <math.h>

int main() {
    char string[100] = "|HG}G}DKBI|Hww}|~GBIN{|gLAB|EBAyyHO|g}HA{DLJGDD|HG}}|~GBIyG|H}Agy~A|K}ACKKBIDG}H}KB|KBMKzK~wIAALFAN";

    for (int i = 5; i >= 1; i--) {
        for (int j = 0; j < 99; j++) {
            string[j] = (10000 * i - 64 - string[j]) % 64 + 64; // 복호화 과정
        }
    }

    printf("%s\n", string); // thisislengthyystringbutIdontknowwhatIshouldfillthisstringwithsoIwrotesomeenglishsentenceverygoodjob
    return 0;
}
