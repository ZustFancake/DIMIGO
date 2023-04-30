#include <stdio.h>
#include <math.h>

int main(){
    char string[100] = "" // Plain text
    
    for (int i = 1; i <= 5; i++){
	    for (int j = 0; j < 99; j++){
	    	string[j] = (10000 * i - string[j]) % 64 + 64;
		}
	}

    printf("%s\n", string); // |HG}G}zK~wDABI}|~GBIN{|gLAB|EBAyyHO|g}HA{DLJGDD|HG}}|~GBIyG|H}Agy~A|K}ACKKBIDG}H}KB|KBMKzK~wIAALFAN
    return 0;
}
